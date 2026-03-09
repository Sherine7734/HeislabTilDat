/**
 * @file
 * @brief Declares a function, an enum and makes an instance that follows the motor direction
 *
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>

/**
 * @brief An enum of the motor driection states: motor direction down,stop and up
 */
typedef enum { 
    OUR_DIRN_DOWN   = -1,
    OUR_DIRN_STOP   = 0,
    OUR_DIRN_UP     = 1
} OurMotorDirection;

/**
 * @brief An instance of our enum of motor direction states, giving the current state
 */
extern OurMotorDirection current_motor_dir_state;

/**
 * @brief Declaration of our function that follows the motor direction
 */
void motor_dir_state_implementation(void);

