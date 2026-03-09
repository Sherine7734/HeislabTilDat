/**
 * @file
 * @brief Declares the functions, gives the states and makes instances for the door and the door obstruction. 
 *
 */


#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>



//State
/**
 * @brief An enum of the door states: closed and open
 */
typedef enum door_state {
    CLOSED, OPEN
} Door_State;

/**
 * @brief An instance of the door state, giving the current state
 */
extern Door_State current_door_state;

/**
 * @brief Declaration of the door state function
 */
void door_state_implementation(void);

//State
/**
 * @brief An enum of the door obstuction states: notobstruct and obstruct
 */
typedef enum obstruction_state {
    NOTOBSTRUCT, OBSTRUCT
} Obstruction_State;

/**
 * @brief An instance of the door obstruction state, giving the current state
 */
extern Obstruction_State current_obstruction_state;

/**
 * @brief Declatration of the door state obstruction function
 */
void door_obstruction(int floor);
