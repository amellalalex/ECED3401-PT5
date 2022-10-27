/*
*
* author: Alex Amellal (#1) (1 > 0)
* author: Ahmed Khairallah (#0) 
* 
*/

#pragma once

// Unstandard C libraries
#include <Windows.h>

#define MAX_NUM_TAXIS 4


//wtf is its name
enum taxi_state{
	TAXI_STATE_IDLE,
	TAXI_STATE_DRIVING,
};

typedef struct pos {
	int x;
	int y;
	int cx;
	int cy;
} Pos;

// x = 1, y = 1, cx = 0, cy = 0

/*
*
* +--*-----+
* |        |
* |   0,0  |
* |   *    |
* +--------+
* 
*/

typedef struct taxi {
	int state;
	Pos taxi_pos;
} Taxi;

typedef struct map {
	int width;
	int height;
	int hchars_per_block;
	int vchars_per_block;
	HANDLE console;
} Map;