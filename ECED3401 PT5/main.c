// Project headers
#include "render.h"

// Standard C libraries
#include <stdio.h>

int main() {
	Map m = (Map){ .width = 5, .height = 5 };

	render_map(m);

	return 0;
}