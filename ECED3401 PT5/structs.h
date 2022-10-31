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
} taxi_state;

enum {
	NORTH = (1 << 0), // 1
	EAST = (1 << 1), // 2
	SOUTH = (1 << 2), // 4
	WEST = (1 << 3), // 8
};

typedef struct pos {
	int x;
	int y;
	int cx;
	int cy;
} Pos;

typedef struct scalar_pos {
	int x;
	int y;
} SPos;

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
	int orientation;
	Pos taxi_pos;
	Pos origin;
	Pos destination;
} Taxi;

typedef struct map {
	int width;
	int height;
	int hchars_per_block;
	int vchars_per_block;
	HANDLE console;
} Map;

/*
*
* Here is how requests are handled:
* 1. All the requests are read from file into memory
* 2. When the time comes, an event is triggered 
* 3. Events are sorted based on time
* 4. A 'next event time' is stored in the event queue to skip ahead
*/

typedef struct request {
	int time;
	int pass_num;
	Pos origin;
	Pos destination;
}  REQ;