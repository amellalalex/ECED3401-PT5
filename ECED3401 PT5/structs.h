#pragma once

#define MAX_NUM_TAXIS 4

enum {
	TAXI_STATE_IDLE,
	TAXI_STATE_DRIVING,
};

typedef struct taxi {
	int state;
	int pos[2];
} Taxi;

typedef struct map {
	int width;
	int height;
	Taxi taxis[MAX_NUM_TAXIS];
} Map;