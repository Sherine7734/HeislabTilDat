/**
 * @file
 * @brief A function and an enum for the order light state, and an instance for each button. 
 *
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>

/**
 * @brief An enum of the orderlight states:off and on
 */
typedef enum order_light_state {
    OFF, ON
} Order_Light_State;

/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_UP0_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_UP1_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_DOWN1_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_UP2_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_DOWN2_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_DOWN3_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */

extern Order_Light_State current_OUTSIDE0_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_OUTSIDE1_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_OUTSIDE2_state;
/**
 * @brief Instance of the orderlight state, giving the current state
 */
extern Order_Light_State current_OUTSIDE3_state;

/**
 * @brief Declaration of the function that set the order light state
 */
void setOrderLightState(void);

