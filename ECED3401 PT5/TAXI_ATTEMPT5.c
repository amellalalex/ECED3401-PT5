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

	// Align blocks first
	if (T->origin.x < T->destination.x) {//if the taxi should go right
		T->orientation = 2;
		T->taxi_pos = offset_cpos(T->taxi_pos, 1, 0);
		
	}
	else if (T->taxi_pos.x > T->destination.x ) {//if the taxi should go left
		T->orientation = 8;
		T->taxi_pos = offset_cpos(T->taxi_pos, -1, 0);
		
	}
	else if (T->origin.y < T->destination.y && T->taxi_pos.x == T->destination.x) {//if the taxi should go north
		T->orientation = 1;
		T->taxi_pos = offset_cpos(T->taxi_pos, 0, 1);
		
	}
	else if (T->origin.y > T->destination.y  && T->taxi_pos.x == T->destination.x) {//if the taxi should go south
		T->orientation = 4;
		T->taxi_pos = offset_cpos(T->taxi_pos, 0, -1);
		
	}
	else if (T->taxi_pos.cx == T->destination.cx && T->taxi_pos.x == T->destination.x && T->taxi_pos.cy == T->destination.cy && T->taxi_pos.y == T->destination.y) {
		T->state = TAXI_STATE_IDLE;
	}
	// Check for block alignment
	else if (T->taxi_pos.x == T->destination.x && T->taxi_pos.y == T->destination.y) {
		if (T->destination.cx != 0) {
			// Move right
			T->orientation = EAST;
			T->taxi_pos.cx++;
		}
		else if (T->destination.cy != 0) {
			// Move down
			T->orientation = SOUTH;
			T->taxi_pos.cy++;
		}
		else {
			// We're done
			T->state = TAXI_STATE_IDLE;
		}
	}

	//if (T->taxi_pos.cx > 10) {
	//	T->taxi_pos.cx = 0;
	//	T->taxi_pos = offset_pos(T->taxi_pos, 1, 0, 1, 0);
	//}

	//if (T->taxi_pos.cx < 0) {
	//	T->taxi_pos.cx = 10;
	//	T->taxi_pos = offset_pos(T->taxi_pos, -1, 0, -1, 0);
	//}

	//if (T->taxi_pos.cy > 6) {
	//	T->taxi_pos.cy = 0;
	//	T->taxi_pos = offset_pos(T->taxi_pos, 0, 1, 0, 1);
	//}

	//if (T->taxi_pos.cy < 0) {//if the lower bound has been reached
	//	T->taxi_pos.cy = 6;
	//	T->taxi_pos = offset_pos(T->taxi_pos, 0, -1, 0, -1);
	//}
}