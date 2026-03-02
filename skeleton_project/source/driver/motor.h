#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>

typedef enum { 
    OUR_DIRN_DOWN   = -1,
    OUR_DIRN_STOP   = 0,
    OUR_DIRN_UP     = 1
} OurMotorDirection;

extern OurMotorDirection current_motor_dir_state;


void motor_dir_state_implementation(void);

