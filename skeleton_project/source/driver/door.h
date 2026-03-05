#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>

//State
typedef enum door_state {
    CLOSED, OPEN
} Door_State;

extern Door_State current_door_state;

void door_state_implementation(void);

//State
typedef enum obstruction_state {
    NOTOBSTRUCT, OBSTRUCT
} Obstruction_State;

extern Obstruction_State current_obstruction_state;

void door_obstruction(int floor);
