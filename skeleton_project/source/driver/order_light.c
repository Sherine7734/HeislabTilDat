#include "order_light.h"

Order_Light_State current_UP0_state = OFF;
Order_Light_State current_UP1_state = OFF;
Order_Light_State current_DOWN1_state = OFF;
Order_Light_State current_UP2_state = OFF;
Order_Light_State current_DOWN2_state = OFF;
Order_Light_State current_DOWN3_state = OFF;

Order_Light_State current_OUTSIDE0_state = OFF;
Order_Light_State current_OUTSIDE1_state = OFF;
Order_Light_State current_OUTSIDE2_state = OFF;
Order_Light_State current_OUTSIDE3_state = OFF;

//Lag en switch for hver order_light_state
//Implementer at lyser fortsetter å lyse fram til orderen har blitt fullført
void setOrderLightState(void){
    switch(current_UP0_state){
    case OFF:
    elevio_buttonLamp(0, BUTTON_HALL_UP, 0);
    if (elevio_callButton(0, BUTTON_HALL_UP) == 1) {
      elevio_buttonLamp(0, BUTTON_HALL_UP, 1);
      current_UP0_state = ON;
    }
    break;
    case ON:{
    elevio_buttonLamp(0, BUTTON_HALL_UP, 1);
    if (elevio_callButton(0, BUTTON_HALL_UP) == 0) {
      elevio_buttonLamp(0, BUTTON_HALL_UP, 0);
      current_UP0_state = OFF;
    }
    }
    break;
    }
}

