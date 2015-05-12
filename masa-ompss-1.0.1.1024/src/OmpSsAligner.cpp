/*******************************************************************************
 *
 * Copyright (c) 2010-2015   Edans Sandes and Guillermo Miranda
 *
 * This file is part of MASA-OmpSs.
 * 
 * MASA-OmpSs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * MASA-OmpSs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with MASA-OmpSs.  If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/

#include "OmpSsAligner.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

#include "config.h"

#define RECOMMENDED_BLOCK_SIZE	(1024)

/**
 * Constructor
 */
OmpSsAligner::OmpSsAligner(AbstractBlockProcessor* blockProcessor = NULL)
		: AbstractBlockAligner(blockProcessor, new OmpSsAlignerParameters()) {
	setPreferredSizes(RECOMMENDED_BLOCK_SIZE, omp_get_max_threads()*2);
}

/**
 * Destructor
 */
OmpSsAligner::~OmpSsAligner() {
}

void OmpSsAligner::scheduleBlocks(int grid_width, int grid_height) {
	if (mustDispatchLastColumn()) {
		/* Here we iterate per diagonals */
		for (int d = 0; d < grid_height+grid_width+1 && mustContinue(); d++) {
			for (int bx=0; bx<=d && bx<grid_width && mustContinue(); bx++) {
				int by=d-bx;
				if (by >= grid_height) continue;
				AbstractBlockAligner::alignBlock(bx, by);
			}
		}
	} else {
		int maxThreads = omp_get_max_threads();
		for (int jj = 0; jj < grid_height || jj<grid_width; jj+=maxThreads) {
			for (int d = 0; d < jj + (2*maxThreads-1); d++) {
				for (int k=0; k<maxThreads && k<=d; k++) {
					int i = d-k;
					int j = jj+k;
					if (i<grid_width && j<grid_height && i<=j) AbstractBlockAligner::alignBlock(i, j);
					if (j<grid_width && i<grid_height && j>i) AbstractBlockAligner::alignBlock(j, i);
				}
			}
		}
	}
	#pragma omp taskwait
}


/**
 * This method aligns block (bx,by).
 *
 * @param bx horizontal coordinate of the block in the grid
 * @param by vertical coordinate of the block in the grid
 */
void OmpSsAligner::alignBlock(int bx, int by, int i0, int j0, int i1, int j1) {
	/* The blocks in the top-most positions must read the first row */
	if (by == 0) {
		/* Receives the first row chunk [j0..j1] from the MASA-core */
		receiveFirstRow(row[bx], j1 - j0);
	}

	/* The blocks in the left-most positions must read the first column */
	if (bx == 0) {
		/* Puts the H[i-1][j-1] dependency in the first cell of the column. */
		col[by][0] = getFirstColumnTail();

		/* Receives the first column chunk from the MASA-core */
		receiveFirstColumn(col[by]+1, i1 - i0);
	}

	/*
	 * The processBlock function executes the SW/NW recurrence function
	 * for all the cells of this block.
	 * See the input/output parameters description in the function implementation.
	 */
	if (!mustContinue()) return; // MASA-core is telling to stop

	/*
	 * The processBlock function executes the SW/NW recurrence function
	 * for all the cells of this block.
	 * See the input/output parameters description in the function implementation.
	 */
	//priority = -std::min(bx, by);
	long long priority = 0;

	//priority = -(bx+by);
	//priority = 0;
	int grid_width = getGrid()->getGridWidth();
	int grid_height = getGrid()->getGridHeight();
	if (mustDispatchLastColumn()) {
		priority = grid_width - bx;
	} else {
		priority = std::min(-i0, -j0);
	}

	/*
	 * Dispatch special rows with a minimum defined distance (getSpecialRowInterval()).
	 * The variable "dispatchThisSpecialRows" defines if this block will dispatch
	 * special rows.
	 */
	int dispatchThisSpecialRows = isSpecialRow(by);

	if (!isBlockPruned(bx, by)) {
		#pragma omp task inout(row[bx][0:(j1-j0-1)], col[by][0:(i1-i0)]) \
						firstprivate( bx, by, j0, j1, i0, i1, dispatchThisSpecialRows ) label( processBlock )\
						out( renamedRow[bx] ) priority( priority )
		{
			if (!mustContinue()) return; // MASA-core is telling to stop
			AbstractBlockAligner::processBlock(bx, by, i0, j0, i1, j1);
			// Copy row
			if (dispatchThisSpecialRows) {
				std::copy( &row[bx][0], &row[bx][j1-j0], &renamedRow[bx][0] );
			}
		}
	} else {
		// This code is executed if the CREATION thread found a pruned block.
		AbstractBlockAligner::ignoreBlock(bx, by);
	}

	/*
	 * If this block produces a special row, we will create a task for it.
	 */
	if (dispatchThisSpecialRows) {
		cell_t first_cell = getFirstColumnTail();
		first_cell.f = -INF;

		#pragma omp task commutative(*rowChain) inout( rowChain[by] ) in( renamedRow[bx] )\
			firstprivate( j0, j1, i1, first_cell ) label( dispatchSpecialRows )
		{
			if (!mustContinue()) return;
			if (bx == 0) {
				/* The left-most blocks must send an extra cell to represent the
				 * very first column of the matrix. */
				dispatchRow(i1, &first_cell, 1);
			}
			dispatchRow(i1, row[bx], j1-j0); // Dispatch the special row.
		}
	}

	/*
	 * The right-most blocks must dispatch the last column to MASA.
	 */
	if (isSpecialColumn(bx)) {
		if (by == 0) {
			/* The left-most blocks must send an extra cell to represent the
			 * very first column of the matrix. */
			cell_t first_cell = getFirstRowTail();
			first_cell.f = -INF;
			dispatchColumn(j1, &first_cell, 1);
		}
		#pragma omp task in( col[by][0:(i1-i0)] ) inout( columnChain )\
			firstprivate( i0, i1, j1, by ) label( dispatchLastColumn )
		{
				dispatchColumn(j1, col[by]+1, i1-i0);
		}
	}
}

/*
 * Changes statistics in a safe way.
 */
void OmpSsAligner::increaseBlockStat(const bool pruned) {
	#pragma omp critical
	{
		AbstractBlockAligner::increaseBlockStat(pruned);
	}
}

/*
 *
 */
void OmpSsAligner::printInitialStatistics(FILE* file) {
	AbstractBlockAligner::printInitialStatistics(file);
	fprintf(file, "Threads: %d\n", omp_get_max_threads());
}

/**
 * Allocate global vectors.
 */
void OmpSsAligner::allocateStructures() {
	AbstractBlockAligner::allocateStructures(); // Superclass first

	/*
	 * gmiranda: row required for renaming.
	 * TODO: Adapt this.
	 */
	int grid_width = getGrid()->getGridWidth();
	int grid_height = getGrid()->getGridHeight();
	rowChain = new char[grid_height];
	renamedRow = new cell_t*[grid_width];
	for (int j=0; j<grid_width; j++) {
		int block_width = getGrid()->getBlockWidth(j,0);
		renamedRow[j] = new cell_t[block_width];
	}

}

/**
 * Deallocate global vectors.
 */
void OmpSsAligner::deallocateStructures() {
	AbstractBlockAligner::deallocateStructures(); // Superclass first
	
	int grid_width = getGrid()->getGridWidth();
	if(renamedRow != NULL) {
		for( int j = 0; j < grid_width; ++j ){
			delete[] renamedRow[j];
		}
		delete[] renamedRow;
		renamedRow = NULL;
	}
	if (rowChain != NULL) {
		delete[] rowChain;
		rowChain = NULL;
	}
}


