#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>

//State
typedef enum order_light_state {
    OFF, ON
} Order_Light_State;

extern Order_Light_State current_UP0_state;
extern Order_Light_State current_UP1_state;
extern Order_Light_State current_DOWN1_state;
extern Order_Light_State current_UP2_state;
extern Order_Light_State current_DOWN2_state;
extern Order_Light_State current_DOWN3_state;

extern Order_Light_State current_OUTSIDE0_state;
extern Order_Light_State current_OUTSIDE1_state;
extern Order_Light_State current_OUTSIDE2_state;
extern Order_Light_State current_OUTSIDE3_state;



