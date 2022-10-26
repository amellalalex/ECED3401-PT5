#pragma once

// Project headers
#include "structs.h"

// Standard C libraries
#include <stdio.h>

// Render settings
#define HCHARS_PER_BLOCK 10
#define VCHARS_PER_BLOCK 6
#define CINTERS '+'
#define CVEDGE '|'
#define CHEDGE '-'
#define CSPACE ' '

// Render flags
enum {
	ROW_INTER_BLOCK,
	ROW_INNER_BLOCK,
};

enum {
	BLOCKR_NORMAL,
	BLOCKR_LAST,
};

// Produces an ASCII rendering of the map and prints it on the screen
void render_map(Map m);