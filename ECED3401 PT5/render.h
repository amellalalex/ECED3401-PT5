/*
* render.h
* 
* Purpose: Render the map data on the screen
* Author: Alex Amellal
* 
*/

#pragma once

// Project headers
#include "structs.h"
#include "util.h"

// Standard C libraries
#include <stdio.h>

// Substandard C libraries
#include <Windows.h>

// Map render chars
#define CINTERS '+'
#define CVEDGE '|'
#define CHEDGE '-'
#define CSPACE ' '

// Taxi render chars
#define CTAXI_FL '<'	// Taxi front (left)
#define CTAXI_FR '>'	// Taxi front (right)
#define CTAXI_B '='		// Taxi back
#define CTAXI_W 'o'		// Taxi wheel

#define VTAXI_FT 'A'	// Taxi front (top)
#define VTAXI_BT 'A'	// Taxi back (vertical up)
#define VTAXI_BB 'V'	// Taxi back (vertical down)
#define VTAXI_FB 'V'	// Taxi front (bottom)

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

// Replaces a character in the map with another character
void render_replace(Map m, Pos pos, char c);

// Renders a taxi on the map
void render_taxi(Map m, Taxi t);

void map_render_loop(Map m);