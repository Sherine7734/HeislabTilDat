/**
 * @file
 * @brief Implementation of setting the order light 
 *
 */


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
/**
 * @brief A functions that switches between order light on and off for each button  
 */
void setOrderLightState(void){
    switch(current_UP0_state){
    case OFF:
    elevio_buttonLamp(0, BUTTON_HALL_UP, 0);
    break;
    case ON:{
    elevio_buttonLamp(0, BUTTON_HALL_UP, 1);
    break;
    }}

    switch(current_UP1_state){
    case OFF:
    elevio_buttonLamp(1, BUTTON_HALL_UP, 0);
    break;
    case ON:{
    elevio_buttonLamp(1, BUTTON_HALL_UP, 1);
    break;
    }}

    switch(current_DOWN1_state){
    case OFF:
    elevio_buttonLamp(1, BUTTON_HALL_DOWN, 0);
    break;
    case ON:{
    elevio_buttonLamp(1, BUTTON_HALL_DOWN, 1);
    break;
    }}

    switch(current_UP2_state){
    case OFF:
    elevio_buttonLamp(2, BUTTON_HALL_UP, 0);
    break;
    case ON:{
    elevio_buttonLamp(2, BUTTON_HALL_UP, 1);
    break;
    }}

    switch(current_DOWN2_state){
    case OFF:
    elevio_buttonLamp(2, BUTTON_HALL_DOWN, 0);
    break;
    case ON:{
    elevio_buttonLamp(2, BUTTON_HALL_DOWN, 1);
    break;
    }}

    switch(current_DOWN3_state){
    case OFF:
    elevio_buttonLamp(3, BUTTON_HALL_DOWN, 0);
    break;
    case ON:{
    elevio_buttonLamp(3, BUTTON_HALL_DOWN, 1);
    break;
    }}

    switch(current_OUTSIDE0_state){
    case OFF:
    elevio_buttonLamp(0, BUTTON_CAB, 0);
    break;
    case ON:{
    elevio_buttonLamp(0, BUTTON_CAB, 1);
    break;
    }}

    switch(current_OUTSIDE1_state){
    case OFF:
    elevio_buttonLamp(1, BUTTON_CAB, 0);
    break;
    case ON:{
    elevio_buttonLamp(1, BUTTON_CAB, 1);
    break;
    }}

    switch(current_OUTSIDE2_state){
    case OFF:
    elevio_buttonLamp(2, BUTTON_CAB, 0);
    break;
    case ON:{
    elevio_buttonLamp(2, BUTTON_CAB, 1);
    break;
    }}

    switch(current_OUTSIDE3_state){
    case OFF:
    elevio_buttonLamp(3, BUTTON_CAB, 0);
    break;
    case ON:{
    elevio_buttonLamp(3, BUTTON_CAB, 1);
    break;
    }}

}

