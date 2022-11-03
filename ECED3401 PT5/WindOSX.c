#include "WindOSX.h"
#include <curses.h>

HANDLE GetStdHandle(int abc) {
	return (HANDLE) {};
}

void Sleep(int msecs) {
	usleep(msecs * 1000);
}

void SetConsoleCursorPosition(HANDLE hdl, COORD coord) {
	move(coord.X, coord.Y);
}

void windosx_init() {
	initscr();
	cbreak();
	noecho();
}
