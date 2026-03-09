/**
 * @file
 * @brief Declaration of a function and an enum for the order state, and an instance for each button
 *
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>
#include "order_light.h"
#include "motor.h"
#include "door.h"

//State
/**
 * @brief An enum off the order states: order off and order on
 */
typedef enum order_state {
    ORDER_OFF, ORDER_ON
} Order_State;

//extern Order_State order0;

/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_UP0_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_UP1_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_DOWN1_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_UP2_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_DOWN2_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_DOWN3_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_OUTSIDE0_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_OUTSIDE1_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_OUTSIDE2_ORDER_state;
/**
 * @brief Instance of the order state, giving the current state
 */
extern Order_State current_OUTSIDE3_ORDER_state;

/**
 * @brief Declaration of function that sets the order
 * @param[in] floor Gives what floor we are on from a floor sensor
 * @param[in] current_door_state Gives the current door state
 * @param[in] current_obstruction_state Gives the current door obstruction state
 */

void setOrder(int floor, Door_State current_door_state, Obstruction_State current_obstruction_state);

