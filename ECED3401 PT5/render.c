/*
* render.c
* 
* Purpose: Render the map data on the screen
* Author: Alex Amellal
* 
*/

#include "render.h"

// Renders a row of chars based on the row type.
// 
// Args:
// flag => specifies the kind of char row to print.
static void render_row(Map m, int flag) {
	switch (flag) {
	case ROW_INTER_BLOCK:
		for (int x = 0; x <= m.width * m.hchars_per_block; x++) {
			// Print intersecting char 
			if (x % m.hchars_per_block == 0) {
				printf("%c", CINTERS);
			}
			else {
				printf("%c", CHEDGE);
			}
		}
		break;
	case ROW_INNER_BLOCK:
		for (int x = 0; x <= m.width * m.hchars_per_block; x++) {
			// Print intersecting char 
			if (x % m.hchars_per_block == 0) {
				printf("%c", CVEDGE);
			}
			else {
				printf("%c", CSPACE);
			}
		}
		break;
	default:
		printf("Invalid flag");
	}
}

// Renders a row of blocks based on the type
//
// Args:
// flag => type of block row to print
void render_blockr(Map m, int flag) {
	// Render first row
	render_row(m, ROW_INTER_BLOCK);
	printf("\n");

	// Print intermittent chars
	for (int y = 1; y < m.vchars_per_block - 1; y++) {
		render_row(m, ROW_INNER_BLOCK);
		printf("\n");
	}
	
	if (flag == BLOCKR_LAST) {
		// Render last row
		render_row(m, ROW_INTER_BLOCK);
	}
}

void render_map(Map m) {
	// Sanity check
	if (m.width < 1 || m.height < 1) {
		// Render error message
		printf("\rInvalid map dimensions (can't render < 1)");
		return;
	}

	// Reset cursor position
	move_cursor(m, (Pos) { .x = 0, .y = 0, .cx = 0, .cy = 0 });

	// Render block rows UP TO n-1
	for (int x = 0; x < m.height-1; x++) {
		render_blockr(m, BLOCKR_NORMAL);
	}

	// Render last block row
	render_blockr(m, BLOCKR_LAST);
	printf("\n");
}

// Replaces a character in the map with another character
void render_replace(Map m, Pos pos, char c) {
	// Update terminal cursor location
	move_cursor(m, pos);

	// Print backspace and desired newchar
	printf("\b%c", c);
}

// Renders a taxi on the map
//
// NOTE: Anchors the back of the taxi on the coordinate
void render_taxi(Map m, Taxi t) {
	switch (t.orientation) {
	case NORTH:
		render_replace(m, offset_cpos(t.taxi_pos, 0, -1), CTAXI_W);
		//render_replace(m, offset_cpos(t.taxi_pos, 0, -1), VTAXI_FT);
		render_replace(m, offset_cpos(t.taxi_pos, 0, 0), VTAXI_BT);
		render_replace(m, offset_cpos(t.taxi_pos, 0, 1), CTAXI_W);
		break;
	case SOUTH:
		render_replace(m, offset_cpos(t.taxi_pos, 0, -1), CTAXI_W);
		render_replace(m, offset_cpos(t.taxi_pos, 0, 0), VTAXI_BB);
		//render_replace(m, offset_cpos(t.taxi_pos, 0, 1), VTAXI_FB);
		render_replace(m, offset_cpos(t.taxi_pos, 0, 1), CTAXI_W);
		break;
	case EAST:
		render_replace(m, offset_cpos(t.taxi_pos, -1, 0), CTAXI_W);
		render_replace(m, offset_cpos(t.taxi_pos, 0, 0), CTAXI_B);
		render_replace(m, offset_cpos(t.taxi_pos, 1, 0), CTAXI_FR);
		render_replace(m, offset_cpos(t.taxi_pos, 2, 0), CTAXI_W);
		break;
	case WEST:
		render_replace(m, offset_cpos(t.taxi_pos, -2, 0), CTAXI_W);
		render_replace(m, offset_cpos(t.taxi_pos, -1, 0), CTAXI_FL);
		render_replace(m, offset_cpos(t.taxi_pos, 0, 0), CTAXI_B);
		render_replace(m, offset_cpos(t.taxi_pos, 1, 0), CTAXI_W);
		break;
	}
}