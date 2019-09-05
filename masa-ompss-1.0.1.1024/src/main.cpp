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

#include <stdio.h>
#include "libmasa/libmasa.hpp"
#include "config.h"
#include "StarPuAligner.hpp"

/**
 * Header of Execution.
 */
#define HEADER 		PACKAGE_STRING"  -  OmpSS tool for huge sequences alignment"

int main ( int argc, char** argv ) {
	return libmasa_entry_point(argc, argv, new StarPuAligner(), HEADER);
}
