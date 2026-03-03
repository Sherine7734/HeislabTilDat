#include "orders.h"


Order_State current_UP0_ORDER_state = ORDER_OFF;
Order_State current_UP1_ORDER_state = ORDER_OFF;
Order_State current_DOWN1_ORDER_state = ORDER_OFF;
Order_State current_UP2_ORDER_state = ORDER_OFF;
Order_State current_DOWN2_ORDER_state = ORDER_OFF;
Order_State current_DOWN3_ORDER_state = ORDER_OFF;
Order_State current_OUTSIDE0_ORDER_state = ORDER_OFF;
Order_State current_OUTSIDE1_ORDER_state = ORDER_OFF;
Order_State current_OUTSIDE2_ORDER_state = ORDER_OFF;
Order_State current_OUTSIDE3_ORDER_state = ORDER_OFF;

void setOrder(int floor){
    switch(current_UP0_ORDER_state){
    case ORDER_OFF:
    current_UP0_state = OFF;
    if ((floor == 0) && (current_UP1_ORDER_state || current_DOWN1_ORDER_state || current_UP2_ORDER_state || current_DOWN2_ORDER_state || current_DOWN3_ORDER_state || current_OUTSIDE1_ORDER_state || current_OUTSIDE2_ORDER_state || current_OUTSIDE3_ORDER_state) == ORDER_ON){
        printf("%s\n", "IF NR 1");
        elevio_motorDirection(DIRN_UP);
        current_motor_dir_state = OUR_DIRN_UP;

    }  
    else if ((floor == 0) && (current_UP0_ORDER_state && current_UP1_ORDER_state && current_DOWN1_ORDER_state && current_UP2_ORDER_state && current_DOWN2_ORDER_state && current_DOWN3_ORDER_state && current_OUTSIDE0_ORDER_state && current_OUTSIDE1_ORDER_state && current_OUTSIDE2_ORDER_state && current_OUTSIDE3_ORDER_state) == ORDER_OFF){
        printf("%s\n", "IF NR 2");
        elevio_motorDirection(DIRN_STOP);
        current_motor_dir_state = OUR_DIRN_STOP; //MAYBE UNNECESSARY??

    }

    if (elevio_callButton(0, BUTTON_HALL_UP) == 1) {

        printf("%s\n", "ORDER UP0 CREATED");
        current_UP0_ORDER_state = ORDER_ON;
        current_UP0_state = ON;
    }
    break;
    case ORDER_ON:
    
    if (floor == 0) {
        elevio_motorDirection(DIRN_STOP);
        current_door_state = OPEN;
        elevio_doorOpenLamp(1);
        sleep(3);
        current_door_state = CLOSED;
        elevio_doorOpenLamp(0);
        printf("%s\n", "ORDER UP0 COMPLETED");
        //if no orders, stay still, otherwise go up. Prioritize which direction to go
        current_UP0_ORDER_state = ORDER_OFF;
        
    }
    
    break;
    }

    switch(current_UP1_ORDER_state){
    case ORDER_OFF:
    current_UP1_state = OFF;
    //Når vi er på vei ned fra DOWN4, og UP2 er på, så går den først ned til UP1, og så opp til UP2
    if (((floor == 1) && ((current_UP2_ORDER_state || current_DOWN2_ORDER_state || current_DOWN3_ORDER_state || current_OUTSIDE2_ORDER_state || current_OUTSIDE3_ORDER_state) == ORDER_ON))){
        printf("%s\n", "YES1");
        elevio_motorDirection(DIRN_UP);
        current_motor_dir_state = OUR_DIRN_UP;

    }  
    else if (((floor == 1) && (current_UP0_ORDER_state && current_UP1_ORDER_state && current_DOWN1_ORDER_state && current_UP2_ORDER_state && current_DOWN2_ORDER_state && current_DOWN3_ORDER_state && current_OUTSIDE0_ORDER_state && current_OUTSIDE1_ORDER_state && current_OUTSIDE2_ORDER_state && current_OUTSIDE3_ORDER_state) == ORDER_OFF) && (current_motor_dir_state == OUR_DIRN_UP)){
            printf("%s\n", "YES2");
            elevio_motorDirection(DIRN_STOP);
            current_motor_dir_state = OUR_DIRN_STOP; 
        }
    
    if (elevio_callButton(1, BUTTON_HALL_UP) == 1) {

        printf("%s\n", "ORDER UP1 CREATED");
        current_UP1_ORDER_state = ORDER_ON;
        current_UP1_state = ON;
    }
    break;
    case ORDER_ON:{
    
    if ((floor == 1) && (current_motor_dir_state == OUR_DIRN_UP)){
        elevio_motorDirection(DIRN_STOP);
        current_door_state = OPEN;
        elevio_doorOpenLamp(1);
        sleep(3);
        current_door_state = CLOSED;
        elevio_doorOpenLamp(0);
        printf("%s\n", "ORDER UP1 COMPLETED");
        //if no orders, stay still, otherwise go up. Prioritize which direction to go
        current_UP1_ORDER_state = ORDER_OFF;
        
    }
    }
    break;
    }

    switch(current_DOWN1_ORDER_state){
    case ORDER_OFF:
    current_DOWN1_state = OFF;
    if (elevio_callButton(1, BUTTON_HALL_DOWN) == 1) {

        printf("%s\n", "ORDER DOWN1 CREATED");
        current_DOWN1_ORDER_state = ORDER_ON;
        current_DOWN1_state = ON;
    }
    break;
    case ORDER_ON:{
    
    if ((floor == 1) && (current_motor_dir_state == OUR_DIRN_DOWN)) {
        printf("%s\n", "ORDER DOWN1 COMPLETED");
        current_DOWN1_ORDER_state = ORDER_OFF;
        
    }
    }
    break;
    }

    switch(current_UP2_ORDER_state){
    case ORDER_OFF:
    current_UP2_state = OFF;
    
    if (((floor == 2) && ((current_DOWN3_ORDER_state || current_OUTSIDE3_ORDER_state) == ORDER_ON))){
        printf("%s\n", "YES11");
        elevio_motorDirection(DIRN_UP);
        current_motor_dir_state = OUR_DIRN_UP;

    }  
    else if (((floor == 2) && (current_UP0_ORDER_state && current_UP1_ORDER_state && current_DOWN1_ORDER_state && current_UP2_ORDER_state && current_DOWN2_ORDER_state && current_DOWN3_ORDER_state && current_OUTSIDE0_ORDER_state && current_OUTSIDE1_ORDER_state && current_OUTSIDE2_ORDER_state && current_OUTSIDE3_ORDER_state) == ORDER_OFF) && (current_motor_dir_state == OUR_DIRN_UP)){
            printf("%s\n", "YES22");
            elevio_motorDirection(DIRN_STOP);
            current_motor_dir_state = OUR_DIRN_STOP; 
        }

    if (elevio_callButton(2, BUTTON_HALL_UP) == 1) {

        printf("%s\n", "ORDER UP2 CREATED");
        current_UP2_ORDER_state = ORDER_ON;
        current_UP2_state = ON;
    }
    break;
    case ORDER_ON:{
    
    if (((floor == 2) && (current_motor_dir_state == OUR_DIRN_UP)) || ((floor == 2) && (current_UP0_ORDER_state && current_UP1_ORDER_state && current_DOWN1_ORDER_state && current_DOWN2_ORDER_state && current_DOWN3_ORDER_state && current_OUTSIDE0_ORDER_state && current_OUTSIDE1_ORDER_state && current_OUTSIDE2_ORDER_state && current_OUTSIDE3_ORDER_state) == ORDER_OFF)){
        elevio_motorDirection(DIRN_STOP);
        current_door_state = OPEN;
        elevio_doorOpenLamp(1);
        sleep(3);
        current_door_state = CLOSED;
        elevio_doorOpenLamp(0);
        printf("%s\n", "ORDER UP2 COMPLETED");
        current_UP2_ORDER_state = ORDER_OFF;
    }
    }
    break;
    }

    switch(current_DOWN2_ORDER_state){
    case ORDER_OFF:
    current_DOWN2_state = OFF;
    if (elevio_callButton(2, BUTTON_HALL_DOWN) == 1) {

        printf("%s\n", "ORDER DOWN2 CREATED");
        current_DOWN2_ORDER_state = ORDER_ON;
        current_DOWN2_state = ON;
    }
    break;
    case ORDER_ON:{
    
    if ((floor == 2) && (current_motor_dir_state == OUR_DIRN_DOWN)) {
        printf("%s\n", "ORDER DOWN2 COMPLETED");
        current_DOWN2_ORDER_state = ORDER_OFF;
        
    }
    }
    break;
    }

    switch(current_DOWN3_ORDER_state){
    case ORDER_OFF:
    current_DOWN3_state = OFF;

    if ((floor == 3) && (current_UP0_ORDER_state || current_UP1_ORDER_state || current_DOWN1_ORDER_state || current_UP2_ORDER_state || current_DOWN2_ORDER_state || current_OUTSIDE0_ORDER_state || current_OUTSIDE1_ORDER_state || current_OUTSIDE2_ORDER_state) == ORDER_ON){
        printf("%s\n", "IF NR 1");
        elevio_motorDirection(DIRN_DOWN);
        current_motor_dir_state = OUR_DIRN_DOWN;

    }  
    else if ((floor == 3) && (current_UP0_ORDER_state && current_UP1_ORDER_state && current_DOWN1_ORDER_state && current_UP2_ORDER_state && current_DOWN2_ORDER_state && current_DOWN3_ORDER_state && current_OUTSIDE0_ORDER_state && current_OUTSIDE1_ORDER_state && current_OUTSIDE2_ORDER_state && current_OUTSIDE3_ORDER_state) == ORDER_OFF){
        printf("%s\n", "IF NR 2");
        elevio_motorDirection(DIRN_STOP);
        current_motor_dir_state = OUR_DIRN_STOP; //MAYBE UNNECESSARY??
    }

    if (elevio_callButton(3, BUTTON_HALL_DOWN) == 1) {

        printf("%s\n", "ORDER DOWN3 CREATED");
        current_DOWN3_ORDER_state = ORDER_ON;
        current_DOWN3_state = ON;
    }
    break;
    case ORDER_ON:
    if (floor == 3) {
        elevio_motorDirection(DIRN_STOP);
        current_door_state = OPEN;
        elevio_doorOpenLamp(1);
        sleep(3);
        current_door_state = CLOSED;
        elevio_doorOpenLamp(0);
        printf("%s\n", "ORDER DOWN3 COMPLETED");
        //if no orders, stay still, otherwise go up. Prioritize which direction to go
        current_DOWN3_ORDER_state = ORDER_OFF;
        
    }
    
    break;
    }

    switch(current_OUTSIDE0_ORDER_state){
    case ORDER_OFF:
    current_OUTSIDE0_state = OFF;
    if ((floor == 0) && (current_UP1_ORDER_state || current_DOWN1_ORDER_state || current_UP2_ORDER_state || current_DOWN2_ORDER_state || current_DOWN3_ORDER_state || current_OUTSIDE1_ORDER_state || current_OUTSIDE2_ORDER_state || current_OUTSIDE3_ORDER_state) == ORDER_ON){
        printf("%s\n", "IF NR 1");
        elevio_motorDirection(DIRN_UP);
        current_motor_dir_state = OUR_DIRN_UP;

    }  
    else if ((floor == 0) && (current_UP0_ORDER_state && current_UP1_ORDER_state && current_DOWN1_ORDER_state && current_UP2_ORDER_state && current_DOWN2_ORDER_state && current_DOWN3_ORDER_state && current_OUTSIDE0_ORDER_state && current_OUTSIDE1_ORDER_state && current_OUTSIDE2_ORDER_state && current_OUTSIDE3_ORDER_state) == ORDER_OFF){
        printf("%s\n", "IF NR 2");
        elevio_motorDirection(DIRN_STOP);
        current_motor_dir_state = OUR_DIRN_STOP; //MAYBE UNNECESSARY??

    }

    if (elevio_callButton(0, BUTTON_CAB) == 1) {

        printf("%s\n", "ORDER OUTSIDE0 CREATED");
        current_OUTSIDE0_ORDER_state = ORDER_ON;
        current_OUTSIDE0_state = ON;
    }
    break;
    case ORDER_ON:
    if (floor == 0) {
        elevio_motorDirection(DIRN_STOP);
        current_door_state = OPEN;
        elevio_doorOpenLamp(1);
        sleep(3);
        current_door_state = CLOSED;
        elevio_doorOpenLamp(0);
        printf("%s\n", "ORDER OUTSIDE0 COMPLETED");
        //if no orders, stay still, otherwise go up. Prioritize which direction to go
        current_OUTSIDE0_ORDER_state = ORDER_OFF;
    }
    break;
    }

    switch(current_OUTSIDE1_ORDER_state){
    case ORDER_OFF:
    current_OUTSIDE1_state = OFF;
    if (elevio_callButton(1, BUTTON_CAB) == 1) {

        printf("%s\n", "ORDER OUTSIDE1 CREATED");
        current_OUTSIDE1_ORDER_state = ORDER_ON;
        current_OUTSIDE1_state = ON;
    }
    break;
    case ORDER_ON:{
    
    if (floor == 1) {
        printf("%s\n", "ORDER OUTSIDE1 COMPLETED");
        current_OUTSIDE1_ORDER_state = ORDER_OFF;
        
    }
    }
    break;
    }

    switch(current_OUTSIDE2_ORDER_state){
    case ORDER_OFF:
    current_OUTSIDE2_state = OFF;
    if (elevio_callButton(2, BUTTON_CAB) == 1) {

        printf("%s\n", "ORDER OUTSIDE2 CREATED");
        current_OUTSIDE2_ORDER_state = ORDER_ON;
        current_OUTSIDE2_state = ON;
    }
    break;
    case ORDER_ON:{
    
    if (floor == 2) {
        printf("%s\n", "ORDER OUTSIDE2 COMPLETED");
        current_OUTSIDE2_ORDER_state = ORDER_OFF;
        
    }
    }
    break;
    }

    switch(current_OUTSIDE3_ORDER_state){
    case ORDER_OFF:
    current_OUTSIDE3_state = OFF;

    if ((floor == 3) && (current_UP0_ORDER_state || current_UP1_ORDER_state || current_DOWN1_ORDER_state || current_UP2_ORDER_state || current_DOWN2_ORDER_state || current_OUTSIDE0_ORDER_state || current_OUTSIDE1_ORDER_state || current_OUTSIDE2_ORDER_state) == ORDER_ON){
        printf("%s\n", "IF NR 1");
        elevio_motorDirection(DIRN_DOWN);
        current_motor_dir_state = OUR_DIRN_DOWN;

    }  
    else if ((floor == 3) && (current_UP0_ORDER_state && current_UP1_ORDER_state && current_DOWN1_ORDER_state && current_UP2_ORDER_state && current_DOWN2_ORDER_state && current_DOWN3_ORDER_state && current_OUTSIDE0_ORDER_state && current_OUTSIDE1_ORDER_state && current_OUTSIDE2_ORDER_state && current_OUTSIDE3_ORDER_state) == ORDER_OFF){
        printf("%s\n", "IF NR 2");
        elevio_motorDirection(DIRN_STOP);
        current_motor_dir_state = OUR_DIRN_STOP; 
    }

    if (elevio_callButton(3, BUTTON_CAB) == 1) {

        printf("%s\n", "ORDER OUTSIDE3 CREATED");
        current_OUTSIDE3_ORDER_state = ORDER_ON;
        current_OUTSIDE3_state = ON;
    }
    break;
    case ORDER_ON:

    if (floor == 3) {
        elevio_motorDirection(DIRN_STOP);
        current_door_state = OPEN;
        elevio_doorOpenLamp(1);
        sleep(3);
        current_door_state = CLOSED;
        elevio_doorOpenLamp(0);
        printf("%s\n", "ORDER OUTSIDE3 COMPLETED");
        current_OUTSIDE3_ORDER_state = ORDER_OFF;
        
    }
    break;
    }
    
}

void handleOrder(void){

}