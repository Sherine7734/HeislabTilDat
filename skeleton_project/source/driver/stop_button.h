#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>
#include "door.h"
#include "motor.h"

void activate_stop_light(void);

void open_door_when_stop(int floor);

//State
typedef enum stop_button_state {
    STOP0, STOP1
} Stop_Button_State;

extern Stop_Button_State current_stop_button_state;

void keep_door_open_when_not_stop(int floor);