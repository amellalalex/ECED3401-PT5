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

// Standard C libraries
#include <stdlib.h>
#include <time.h>

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

// Generates a random position within the provided map
Pos get_random_pos(Map m);

// Returns the next position of the taxi's path
Pos next_pos(Map m, Taxi t);

// Determines heading with respect to positions
int determine_heading(Map m, Pos src, Pos dest);

// Return heading with respect to block position ONLY
int get_block_heading(Pos src, Pos dest);

// Return heading with respect to character position ONLY
int get_char_heading(Pos src, Pos dest);

// Returns the English version of the heading
char* get_heading_msg(Map m, Pos src, Pos dest);

// Returns scalar positions (absolute) from position
//
// NOTE: Both the x/y and cx/cy pairs will contain the absolute position pairs.
SPos get_scalar(Map m, Pos pos);

// Returns grid position (relative) from scalar position.
Pos get_pos(Map m, SPos s);

///////////////////////////
//		Windows Util	 //
///////////////////////////

// Moves the terminal cursor to the absolute posiiton provided
void move_cursor(Map m, Pos p);