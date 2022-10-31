#include "taxi.h"
#include "util.h"
Taxi Num_of_Taxis[MAX_NUM_TAXIS];

Taxi spawn_taxi(Map m) {
	Pos origin = get_random_pos(m);
	return (Taxi) {
		.origin = origin,
		.destination = get_random_pos(m),
		.taxi_pos = origin,
		.state = TAXI_STATE_DRIVING,
	};
}

void update_taxi(Taxi* T, Map m) {
	for (int i = 0; i < MAX_NUM_TAXIS; i++) {
		navigate_taxi(&T[i], m);
	}
}

void navigate_taxi(Taxi* T, Map m) {
	//we need to account for the taxi driving to the left and down as
	//well since this only makes it go to the right and up
	//there will  be 4 cases: up right up left down right down left
	//Up y++ cy++ down y-- cy-- right x++ cx++ and left x-- cx--

	// Create scalar position
	SPos scalar = get_scalar(m, T->taxi_pos);

	// Head towards block first
	int block_heading = get_block_heading(T->taxi_pos, T->destination);
	int char_heading = get_char_heading(T->taxi_pos, T->destination);

	if (block_heading) {
		switch (block_heading) {
		case NORTH:
			scalar.y--;
			break;
		case EAST:
			scalar.x++;
			break;
		case SOUTH:
			scalar.y++;
			break;
		case WEST:
			scalar.x--;
			break;
		}
	}
	else if (char_heading) {
		switch (char_heading) {
		case NORTH:
			scalar.y--;
			break;
		case EAST:
			scalar.x++;
			break;
		case SOUTH:
			scalar.y++;
			break;
		case WEST:
			scalar.x--;
			break;
		}
	}
	else {
		T->state = TAXI_STATE_IDLE;
	}
	
	T->taxi_pos = get_pos(m, scalar);
}