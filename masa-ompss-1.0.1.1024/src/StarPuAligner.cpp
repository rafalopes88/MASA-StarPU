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

#include "StarPuAligner.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <signal.h>
#include <starpu.h>
#include <iostream>

using namespace std;

#include "config.h"

#define RECOMMENDED_BLOCK_SIZE	(1024)

#define FPRINTF(ofile, fmt, ...) do { if (!getenv("STARPU_SSILENT")) {fprintf(ofile, fmt, ## __VA_ARGS__); }} while(0)

struct starpu_codelet cl;

struct CpuParams{
	int bx, by,  i0,  j0,  i1, j1, dispatchThisSpecialRows;
	StarPuAligner *func; 
};
/**
 * Constructor
 */
StarPuAligner::StarPuAligner(AbstractBlockProcessor* blockProcessor = NULL)
		: AbstractBlockAligner(blockProcessor, new StarPuAlignerParameters()) {
	int ret;

	

	ret = starpu_init(NULL);

	if (ret == -ENODEV)
		FPRINTF(stderr, "Erro 77");
	STARPU_CHECK_RETURN_VALUE(ret, "starpu_init");

	unsigned ncpus =  starpu_cpu_worker_get_count();
	
	

	starpu_codelet_init(&cl);
	cl.cpu_funcs[0] = StarPuAligner::callBack;
	cl.cpu_funcs_name[0] = "processBlock";
	setPreferredSizes(RECOMMENDED_BLOCK_SIZE,starpu_cpu_worker_get_count()*2);
}

/**
 * Destructor
 */
StarPuAligner::~StarPuAligner() {
}

void StarPuAligner::scheduleBlocks(int grid_width, int grid_height) {

	int ret;

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
		int maxThreads = starpu_cpu_worker_get_count();
		
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
	starpu_task_wait_for_all();
}

void StarPuAligner::callBack(void *descr[], void *_args){

	struct CpuParams *params = static_cast<CpuParams*>(_args);


	params->func->processBlock(params->bx, params->by,  params->i0,  params->j0,  params->i1, params->j1, params->dispatchThisSpecialRows);
	
}

void StarPuAligner::processBlock(int bx, int by, int i0, int j0, int i1, int j1, int dispatchThisSpecialRows){
	if (!mustContinue()) return; // MASA-core is telling to stop
	
	AbstractBlockAligner::processBlock(bx, by, i0, j0, i1, j1 );
	// Copy row
	if (dispatchThisSpecialRows) {
		std::copy( &row[bx][0], &row[bx][j1-j0], &renamedRow[bx][0] );
	}
}

/**
 * This method aligns block (bx,by).
 *
 * @param bx horizontal coordinate of the block in the grid
 * @param by vertical coordinate of the block in the grid
 */
void StarPuAligner::alignBlock(int bx, int by, int i0, int j0, int i1, int j1) {
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
		struct CpuParams *params;
		params->bx = bx;
		params->by = by;
		params->i0 = i0;
		params->j0 = j0;
		params->i1 = i1;
		params->j1 = j1;

		struct starpu_task *task = starpu_task_create();

		task->cl = &cl;
		task->cl_arg = params;

		task->use_tag = 1;
		 //#pragma omp task inout(row[bx][0:(j1-j0-1)], col[by][0:(i1-i0)]) \
		// 				firstprivate( bx, by, j0, j1, i0, i1, dispatchThisSpecialRows ) label( processBlock )\
		// 				out( renamedRow[bx] ) priority( priority )
		// {
		// 	StarPuAligner::processBlock(bx, by, i0, j0, i1, j1)
		// }
		//StarPuAligner::processBlock(bx, by, i0, j0, i1, j1, dispatchThisSpecialRows);
	} else {
		// This code is executed if the CREATION thread found a pruned block.
		AbstractBlockAligner::ignoreBlock(bx, by);
	}

	// /*
	//  * If this block produces a special row, we will create a task for it.
	//  */
	// if (dispatchThisSpecialRows) {
	// 	cell_t first_cell = getFirstColumnTail();
	// 	first_cell.f = -INF;

	// 	#pragma omp task commutative(*rowChain) inout( rowChain[by] ) in( renamedRow[bx] )\
	// 		firstprivate( j0, j1, i1, first_cell ) label( dispatchSpecialRows )
	// 	{
	// 		if (!mustContinue()) return;
	// 		if (bx == 0) {
	// 			/* The left-most blocks must send an extra cell to represent the
	// 			 * very first column of the matrix. */
	// 			dispatchRow(i1, &first_cell, 1);
	// 		}
	// 		dispatchRow(i1, row[bx], j1-j0); // Dispatch the special row.
	// 	}
	// }

	// /*
	//  * The right-most blocks must dispatch the last column to MASA.
	//  */
	// if (isSpecialColumn(bx)) {
	// 	if (by == 0) {
	// 		/* The left-most blocks must send an extra cell to represent the
	// 		 * very first column of the matrix. */
	// 		cell_t first_cell = getFirstRowTail();
	// 		first_cell.f = -INF;
	// 		dispatchColumn(j1, &first_cell, 1);
	// 	}
	// 	#pragma omp task in( col[by][0:(i1-i0)] ) inout( columnChain )\
	// 		firstprivate( i0, i1, j1, by ) label( dispatchLastColumn )
	// 	{
	// 			dispatchColumn(j1, col[by]+1, i1-i0);
	// 	}
	// }
}

/*
 * Changes statistics in a safe way.
 */
void StarPuAligner::increaseBlockStat(const bool pruned) {
	// #pragma omp critical
	// {
	// 	AbstractBlockAligner::increaseBlockStat(pruned);
	// }
}

/*
 *
 */
void StarPuAligner::printInitialStatistics(FILE* file) {
	// AbstractBlockAligner::printInitialStatistics(file);
	// fprintf(file, "Threads: %d\n", omp_get_max_threads());
}

/**
 * Allocate global vectors.
 */
void StarPuAligner::allocateStructures() {
	 AbstractBlockAligner::allocateStructures(); // Superclass first

	// /*
	//  * gmiranda: row required for renaming.
	//  * TODO: Adapt this.
	//  */
	// int grid_width = getGrid()->getGridWidth();
	// int grid_height = getGrid()->getGridHeight();
	// rowChain = new char[grid_height];
	// renamedRow = new cell_t*[grid_width];
	// for (int j=0; j<grid_width; j++) {
	// 	int block_width = getGrid()->getBlockWidth(j,0);
	// 	renamedRow[j] = new cell_t[block_width];
	// }

}

/**
 * Deallocate global vectors.
 */
void StarPuAligner::deallocateStructures() {
	// AbstractBlockAligner::deallocateStructures(); // Superclass first
	
	// int grid_width = getGrid()->getGridWidth();
	// if(renamedRow != NULL) {
	// 	for( int j = 0; j < grid_width; ++j ){
	// 		delete[] renamedRow[j];
	// 	}
	// 	delete[] renamedRow;
	// 	renamedRow = NULL;
	// }
	// if (rowChain != NULL) {
	// 	delete[] rowChain;
	// 	rowChain = NULL;
	// }
}


