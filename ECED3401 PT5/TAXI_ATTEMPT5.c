#include "taxi.h"
#include "util.h"
Taxi Num_of_Taxis[MAX_NUM_TAXIS];



void update_taxi(Taxi* T, map m) {
	Pos destination;
	destination.cx = 2;
	destination.cy = 2;
	destination.x = 2;
	destination.y = 2;

	for (int i = 0; i < MAX_NUM_TAXIS; i++) {
		navigate_taxi(&T[i], m);
	}
}

void navigate_taxi(Taxi* T, map m) {
	//we need to account for the taxi driving to the left and down as
	//well since this only makes it go to the right and up
	//there will  be 4 cases: up right up left down right down left
	//Up y++ cy++ down y-- cy-- right x++ cx++ and left x-- cx--
	T->destination = get_random_pos(m);
	T->origin = get_random_pos(m);
	T->taxi_pos = T->origin;
	T->state = TAXI_STATE_DRIVING;
	while (T->state) {//While taxi is driving
		if (T->origin.x < T->destination.x) {//if the taxi should go right
			T->orientation=
			while (T->taxi_pos.x < T->destination.x) {
				while (T->taxi_pos.cx < T->destination.cx) {
					T->taxi_pos.cx++;
				}
				T->taxi_pos.x++;
			}
		}
		if (T->taxi_pos.x > final_pos.x) {//if the taxi should go left
			while (T->taxi_pos.x > final_pos.x) {
				while (T->taxi_pos.cx > final_pos.cx) {
					T->taxi_pos.cx--;
				}
				T->taxi_pos.x--;
			}
		}
		if (T->taxi_pos.y < final_pos.y) {//if the taxi should go up
			while (T->taxi_pos.y < final_pos.y) {
				while (T->taxi_pos.cy < final_pos.cy) {
					T->taxi_pos.cy++;
				}
				T->taxi_pos.y++;
			}
		}
		if (T->taxi_pos.y > final_pos.y) {//if the taxi should go down
			while (T->taxi_pos.y > final_pos.y) {
				while (T->taxi_pos.cy > final_pos.cy) {
					T->taxi_pos.cy--;
				}
				T->taxi_pos.y--;
			}
		}
		if (T->taxi_pos.cx == final_pos.cx && T->taxi_pos.cy == final_pos.cy && T->taxi_pos.x == final_pos.x && T->taxi_pos.y == final_pos.y) {
			T->state = TAXI_STATE_IDLE;
		}
	}

}