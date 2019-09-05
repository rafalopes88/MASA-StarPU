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

#ifndef OMPSSALIGNER_HPP_
#define OMPSSALIGNER_HPP_

#include "libmasa/libmasa.hpp"
#include "StarPuAlignerParameters.hpp"

#include <starpu.h>
/**
 *
 * This is an Example class that extends MASA to a simple CPU architecture.
 * Here we have an implementation of all pure virtual methods from the
 * AbstractAligner. Many capabilities was implemented in order to allow
 * the use of many MASA features.
 */
class StarPuAligner : public AbstractBlockAligner {
public:
	/**
	 * Constructor
	 */
	StarPuAligner(AbstractBlockProcessor* blockProcessor = NULL);

	/**
	 * Destructor.
	 */
	~StarPuAligner();

	void processBlock(int bx, int by, int i0, int j0, int i1, int j1, int dispatchThisSpecialRows);

	static void callBack(void *descr[], void *_args);

	virtual void printInitialStatistics(FILE* file);

protected:
	virtual void scheduleBlocks(int grid_width, int grid_height);
	virtual void alignBlock(int bx, int by, int i0, int j0, int i1, int j1);

	virtual void allocateStructures();
	virtual void deallocateStructures();

	virtual void increaseBlockStat(const bool pruned);

private:
	
	
	cell_t** renamedRow;

	// Sentinels
	char* rowChain;
	char columnChain;
	
};
//extern static score_t bestScore;

#endif /* OMPSSALIGNER_HPP_ */
