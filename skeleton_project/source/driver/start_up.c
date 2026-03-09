/**
 * @file
 * @brief Implementation of startup routine 
 *
 */
#include "start_up.h"

/**
 * @brief Startup function that sends the elevator to floor 0, if not already there
 * @param[in] floor Gives what floor we are on from a floor sensor
 */
void start_up(int floor){
    printf("%s\n", "Start up");
    
    elevio_motorDirection(DIRN_DOWN);
    current_motor_dir_state = OUR_DIRN_DOWN;
    if (floor > 3){
        floor = 3;
    } else if (floor < -1){
        floor = 0;
    }
    
    if (floor == 0){
        elevio_motorDirection(DIRN_STOP);
        current_motor_dir_state = OUR_DIRN_STOP;
    }

    //If we have not reached a floor, ignore all orders
}