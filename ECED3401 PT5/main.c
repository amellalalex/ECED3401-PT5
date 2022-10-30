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

	Taxi taxis[MAX_NUM_TAXIS];
	for (int x = 0; x < MAX_NUM_TAXIS; x++) {
		taxis[x] = (Taxi){
			.state = TAXI_STATE_DRIVING,
			.origin = get_random_pos(m),
			.destination = get_random_pos(m),
		};
		taxis[x].taxi_pos = taxis[x].origin;
	}

	int driving_taxis = MAX_NUM_TAXIS;
	while (driving_taxis > 0) {



		driving_taxis = 0;
		for (int x = 0; x < MAX_NUM_TAXIS; x++) {
			if (taxis[x].state == TAXI_STATE_DRIVING) {
				driving_taxis++;
			}
		}
	}

	getchar();
	return 0;
}
