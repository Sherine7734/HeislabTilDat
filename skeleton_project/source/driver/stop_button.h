/**
 * @file
 * @brief Declaration for functions realted to the stop button, an enum of the stopbutton states and an instance of the enum 
 *
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>
#include "door.h"
#include "motor.h"
#include "orders.h"

void activate_stop_light(void);

void open_door_when_stop(int floor);

//State
/**
 * @brief An enum for the stop button states: not pressed (STOP0) and pressed (STOP1)
 */
typedef enum stop_button_state {
    STOP0, STOP1
} Stop_Button_State;

/**
 * @brief An instance of the stop button enum, giving the current state
 */

extern Stop_Button_State current_stop_button_state;

void keep_door_open_when_not_stop(int floor);