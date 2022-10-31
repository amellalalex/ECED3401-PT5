#pragma once
#include "structs.h"

//function to scan taxi
void update_taxi(Taxi* T, Map m);

Taxi spawn_taxi(Map m);

void navigate_taxi(Taxi * T, Map m);
