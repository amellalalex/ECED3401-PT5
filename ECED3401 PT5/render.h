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

// Standard C libraries
#include <stdio.h>

// Substandard C libraries
#include <Windows.h>

// Render settings
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

// Replaces a character in the map with another character
void render_replace(Map m, Pos pos, char c);

void render_taxi(Map m, Taxi t);

void map_render_loop(Map m);