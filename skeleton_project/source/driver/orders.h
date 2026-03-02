#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "elevio.h"
#include <time.h>
#include <unistd.h>
#include "order_light.h"

//State
typedef enum order_state {
    ORDER_OFF, ORDER_ON
} Order_State;

extern Order_State order0;


extern Order_State current_UP0_ORDER_state;
extern Order_State current_UP1_ORDER_state;
extern Order_State current_DOWN1_ORDER_state;
extern Order_State current_UP2_ORDER_state;
extern Order_State current_DOWN2_ORDER_state;
extern Order_State current_DOWN3_ORDER_state;
extern Order_State current_OUTSIDE0_ORDER_state;
extern Order_State current_OUTSIDE1_ORDER_state;
extern Order_State current_OUTSIDE2_ORDER_state;
extern Order_State current_OUTSIDE3_ORDER_state;

void setOrder(int floor);

