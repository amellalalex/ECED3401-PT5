// Project headers
#include "render.h"
#include "taxi.h"

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

	// Init taxis
	Taxi taxis[MAX_NUM_TAXIS];
	for (int x = 0; x < MAX_NUM_TAXIS; x++) {
		taxis[x] = spawn_taxi(m);
	}

	int driving_taxis = MAX_NUM_TAXIS;
	while (driving_taxis > 0) {
		// Re-render map
		render_map(m);

		printf("\n\n");
		for (int x = 0; x < MAX_NUM_TAXIS; x++) {
			char* block_heading_msg = get_heading_msg(m, taxis[x].taxi_pos, taxis[x].destination);
			char* char_heading_msg = get_heading_msg(m, taxis[x].taxi_pos, taxis[x].destination);
			printf(
				"taxis[%d] => pos: {(%d, %d), (%d, %d)}, dest: {(%d, %d), (%d, %d)}, BLOCK_HEADING: %s, CHAR_HEADING: %s\n", x,
				taxis[x].taxi_pos.x, taxis[x].taxi_pos.y, taxis[x].taxi_pos.cx, taxis[x].taxi_pos.cy,
				taxis[x].destination.x, taxis[x].destination.y, taxis[x].destination.cx, taxis[x].destination.cy,
				block_heading_msg, char_heading_msg
			);
		}

		// Update taxi pos & render
#ifdef DEBUG
		for (int x = 0; x < MAX_NUM_TAXIS; x++) {
			taxis[x].taxi_pos = next_pos(m, taxis[x]);
			render_taxi(m, taxis[x]);
		}
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

		Sleep(500);
	}

	getchar();
	return 0;
}
