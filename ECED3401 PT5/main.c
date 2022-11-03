// Project headers
#include "render.h"
#include "taxi.h"

// Standard C libraries
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

// Substandard C libraries
#if defined(_WIN32)
	#include <Windows.h>
#elif defined(__APPLE__)
	#include "WindOSX.h"
#endif

int main(int argc, char *argv[]) {
#ifdef __APPLE__
	windosx_init();
#endif

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

	// Init taxis
	Taxi taxis[MAX_NUM_TAXIS];
	for (int x = 0; x < MAX_NUM_TAXIS; x++) {
		taxis[x] = spawn_taxi(m);
	}

	int driving_taxis = MAX_NUM_TAXIS;
	while (driving_taxis > 0) {
		// Re-render map
		render_map(m);


		// Update taxi pos & render
#ifdef DEBUG
#ifdef _WIN32
		printf("\n\n");
		for (int x = 0; x < MAX_NUM_TAXIS; x++) {
			int heading = get_block_heading(taxis[x].taxi_pos, taxis[x].destination);
			if (!heading) {
				heading = get_char_heading(taxis[x].taxi_pos, taxis[x].destination);
			}
			char* heading_msg = get_heading_msg(heading);
			printf(
				"taxis[%d] => pos: {(%d, %d), (%d, %d)}, dest: {(%d, %d), (%d, %d)}, HEADING: %s                 \n", x,
				taxis[x].taxi_pos.x, taxis[x].taxi_pos.y, taxis[x].taxi_pos.cx, taxis[x].taxi_pos.cy,
				taxis[x].destination.x, taxis[x].destination.y, taxis[x].destination.cx, taxis[x].destination.cy,
				heading_msg
			);
		}
		for (int x = 0; x < MAX_NUM_TAXIS; x++) {
			taxis[x].taxi_pos = next_pos(m, taxis[x]);
			render_taxi(m, taxis[x]);
		}
#endif
#endif // DEBUG
		update_taxi(taxis, m);
		for (int x = 0; x < MAX_NUM_TAXIS; x++) {
			render_taxi(m, taxis[x]);
		}
		// Count driving taxis
		driving_taxis = 0;
		for (int x = 0; x < MAX_NUM_TAXIS; x++) {
			if (taxis[x].state == TAXI_STATE_DRIVING) {
				driving_taxis++;
			}
		}

		Sleep(250);
	}

	getchar();
	return 0;
}
