/*
*
* util.c
*
* Purpose: Useful miscellaneous functions to support development
* Author: Alex Amellal
*
*/

// Project libraries
#include "util.h"

// Offset a position (blocks AND chars).
Pos offset_pos(Pos p, int xoff, int yoff, int cxoff, int cyoff) {
	return (Pos) {
		.x = p.x + xoff,
		.y = p.y + yoff,
		.cx = p.cx + cxoff,
		.cy = p.cy + cyoff,
	};
}

// Offset a position by blocks only.
Pos offset_bpos(Pos p, int xoff, int yoff) {
	return (Pos) {
		.x = p.x + xoff,
		.y = p.y + yoff,
		.cx = p.cx,
		.cy = p.cy,
	};
};

// Offset a position by chars only.
Pos offset_cpos(Pos p, int cxoff, int cyoff) {
	return (Pos) {
		.x = p.x,
		.y = p.y,
		.cx = p.cx + cxoff,
		.cy = p.cy + cyoff,
	};
}

// Moves the terminal cursor to the map position provided.
void move_cursor(Map m, Pos pos) {
	// Calculate absolute position in chars
	int x = pos.x * m.hchars_per_block + pos.cx;
	int y = pos.y * (m.vchars_per_block - 1) + pos.cy; // -1 because normal blocks lack last row

	// Update terminal cursor location
	COORD coord = { .X = x, .Y = y };
	SetConsoleCursorPosition(m.console, coord);
}