// Project headers
#include "render.h"

// Standard C libraries
#include <stdio.h>
#include <stdlib.h>

// Substandard C libraries
#include <Windows.h>

void loop() {
	//update_taxis();
	//update_map();

	Sleep(1000);
}

int main(int argc, char *argv[]) {
	// Check argc 
	if(argc != 3) {
		printf("[!] Invalid number of args. Try ./a.out <width> <height>\n");
		return -1;
	}

	int width = atoi(argv[1]);
	int height = atoi(argv[2]);

	Map m = (Map){ 
		.width = width, 
		.height = height, 
		.hchars_per_block = 10, 
		.vchars_per_block = 6,
		.console = GetStdHandle(STD_OUTPUT_HANDLE),
	};

	render_map(m);

	render_replace(m, (Pos) { .x = 0, .y = 0, .cx = 5, .cy = 3 }, 'X');
	render_replace(m, (Pos) { .x = 0, .y = 0, .cx = 5, .cy = 4 }, 'X');
	render_replace(m, (Pos) { .x = 0, .y = 0, .cx = 4, .cy = 3 }, 'X');
	render_replace(m, (Pos) { .x = 0, .y = 0, .cx = 4, .cy = 4 }, 'X');

	for (;;) {
		loop();
	}

	getchar();
	return 0;
}
