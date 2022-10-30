// Project headers
#include "render.h"

// Standard C libraries
#include <stdio.h>
#include <stdlib.h>

// Substandard C libraries
#include <Windows.h>

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

	Taxi t = (Taxi){
		.taxi_pos = {.x = 1, .y = 2, .cx = 3, .cy = 0},
	};

	for (;;) {
		Pos randp = get_random_pos(m);
		printf("get_random_pos(m) = (Pos) { .x = %d, .y = %d, .cx = %d, .cy = %d }\n", randp.x, randp.y, randp.cx, randp.cy);
		Sleep(500);
	}

	for (;;) {
		//update_taxis();

		// Render 
		render_map(m);
		render_taxi(m, t);

		// Update
		t.taxi_pos = offset_cpos(t.taxi_pos, 1, 0);
		t.orientation++;
		if (t.orientation > WEST) {
			t.orientation = NORTH;
		}

		Sleep(500);
	}

	getchar();
	return 0;
}
