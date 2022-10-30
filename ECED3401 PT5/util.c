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

// Generates a random position within the provided map
Pos get_random_pos(Map m) {
	// Establish boundaries
	int maxx = m.width * m.hchars_per_block;
	int maxy = m.height * m.vchars_per_block;

	// Choose random absolute position
	int randx = rand() % (maxx - 1);
	int randy = rand() % (maxy - 1);

	// Cast onto position
	Pos pos = (Pos){
		.x = randx / m.hchars_per_block,
		.y = randy / m.vchars_per_block,
		.cx = randx % m.hchars_per_block,
		.cy = randy % m.vchars_per_block,
	};

	// Quantize onto road (pick closest)
	int dt = pos.cy;
	int db = m.vchars_per_block - pos.cy;
	int dl = pos.cx;
	int dr = m.hchars_per_block - pos.cx;

	// X or Y axis quantization
	if (min(dt, db) < min(dl, dr)) {
		// Quantize to Y
		if (dt < db) {
			pos.cy = 0;
		}
		else {
			pos.y++;
			pos.cy = 0;
		}
	}
	else {
		// Quantize to X
		if (dl < dr) {
			pos.cx = 0;
		}
		else {
			pos.x++;
			pos.cx = 0;
		}
	}

	return pos;
}

// Returns scalar positions (absolute) from position
//
// NOTE: Both the x/y and cx/cy pairs will contain the absolute position pairs.
Pos get_scalar(Map m, Pos pos) {
	int x = pos.x * m.hchars_per_block + pos.cx;
	int y = pos.y * m.vchars_per_block + pos.cy;

	return (Pos) {
		.x = x,
		.y = y,
		.cx = x,
		.cy = y,
	};
}

// Determines heading with respect to positions
//
// NOTE: Don't forget that y increases going down (y-inverted)
// NOTE: North is pointing 'up' towards the negative Y direction
//
// Returns: Flag combination of N/E/S/W (OR'd) or 0 in case destination is reached
int determine_heading(Map m, Pos src, Pos dest) {
	Pos scalar_src = get_scalar(m, src);
	Pos scalar_dest = get_scalar(m, dest);

	// Determine heading
	int heading = 0;
	if (scalar_src.x < scalar_dest.x) {
		heading |= EAST;
	}
	else if (scalar_src.x > scalar_dest.x) {
		heading |= WEST;
	}

	if (scalar_src.y < scalar_dest.y) {
		heading |= SOUTH;
	}
	else if (scalar_src.y > scalar_dest.y) {
		heading |= NORTH;
	}

	return heading;
}