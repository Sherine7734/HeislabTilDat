#include "start_up.h"


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