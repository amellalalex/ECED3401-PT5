#pragma once

#ifdef __APPLE__

#include <unistd.h>
#include <curses.h>

#define STD_OUTPUT_HANDLE 0

typedef struct handle {

} HANDLE;

HANDLE GetStdHandle(int abc);

void Sleep(int msecs);

typedef struct coord {
	int X;
	int Y;
} COORD;

void SetConsoleCursorPosition(HANDLE hdl, COORD coord);

#define min(x, y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) < (y)) ? (y) : (x))

void windosx_init();

#endif // APPLE 
