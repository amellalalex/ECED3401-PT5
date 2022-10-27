/*
*
* util.h
* 
* Purpose: Useful miscellaneous functions to support development
* Author: Alex Amellal
* 
*/

#pragma once

// Project libraries
#include "structs.h"

// Substandard C libraries
#include <Windows.h>

//////////////
// Pos Util //
//////////////

// Offset a position (blocks AND chars).
Pos offset_pos(Pos p, int xoff, int yoff, int cxoff, int cyoff);

// Offset a position by blocks only.
Pos offset_bpos(Pos p, int xoff, int yoff);

// Offset a position by chars only.
Pos offset_cpos(Pos p, int cxoff, int cyoff);

///////////////////////////
//		Windows Util	 //
///////////////////////////

// Moves the terminal cursor to the absolute posiiton provided
void move_cursor(Map m, Pos p);