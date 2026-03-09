/**
 * @file
 * @brief Implementation of stoplight, open door when elevator is stopped and keep door open when not stopped after stop for stopbutton
 *
 */
#include "stop_button.h"

/**
 * @brief Turns stop light on if the stopbutton is pressed, and turns the stop light off if stop button is not pressed
 */
void activate_stop_light(void) {
    if (elevio_stopButton() == 1) {
        //printf("%s\n", "Stop lamp on");
        elevio_stopLamp(1);
    } 
    if (elevio_stopButton() == 0) {
        //printf("%s\n", "Stop lamp off");
        elevio_stopLamp(0);
    }
}

/**
 * @brief Opens the door if the stopbutton is pressed while in a floor
 */
void open_door_when_stop(int floor){
    if ((floor != -1) && (elevio_stopButton() == 1)) {
        current_door_state = OPEN;
    }
}

Stop_Button_State current_stop_button_state  = STOP0;

/**
 * @brief Switches between the stopbutton states, deletes orders after pressed and keeps door open for three seconds after released if we are in a floor
 * @param[in] floor Gives what floor we are on from a floor sensor
 */
void keep_door_open_when_not_stop(int floor){
    

    switch(current_stop_button_state) {
    
    case STOP0:
        //printf("%s\n", "In STOP0");
        if (elevio_stopButton()==1) {
            current_stop_button_state=STOP1;
        }
        break;
    case STOP1:
        //printf("%s\n", "In STOP1");
        elevio_motorDirection(DIRN_STOP);
        current_motor_dir_state = OUR_DIRN_STOP;

        current_UP0_ORDER_state = ORDER_OFF;
        current_UP1_ORDER_state = ORDER_OFF;
        current_DOWN1_ORDER_state = ORDER_OFF;
        current_UP2_ORDER_state = ORDER_OFF;
        current_DOWN2_ORDER_state = ORDER_OFF;
        current_DOWN3_ORDER_state = ORDER_OFF;
        current_OUTSIDE0_ORDER_state = ORDER_OFF;
        current_OUTSIDE1_ORDER_state = ORDER_OFF;
        current_OUTSIDE2_ORDER_state = ORDER_OFF;
        current_OUTSIDE3_ORDER_state = ORDER_OFF;

        if ((elevio_stopButton()==0)  && (floor != -1)){
            printf("%s\n", "Timer has started");
            current_door_state = OPEN;
            sleep(3);
            current_door_state = CLOSED;
            //fix direction after stop
            printf("%s\n", "Timer has ended");
            current_stop_button_state=STOP0;
        } else if (floor == -1) {
            current_door_state = CLOSED;
        }
        break;
    
    }
}

/*
if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            activate_stop_light();}

*/