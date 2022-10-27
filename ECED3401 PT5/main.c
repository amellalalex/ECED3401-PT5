// Project headers
#include "render.h"

// Standard C libraries
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Check argc 
	if(argc != 3) {
		printf("[!] Invalid number of args. Try ./a.out <width> <height>\n");
		return -1;
	}

	int width = atoi(argv[1]);
	int height = atoi(argv[2]);

	Map m = (Map){ .width = width, .height = height };

	render_map(m);
	getchar();
	return 0;
}
