#include "motor.h"

OurMotorDirection current_motor_dir_state = OUR_DIRN_DOWN;



//A function that chooses which motor direction state we are in
void motor_dir_state_implementation(void){
    switch(current_motor_dir_state){
    case OUR_DIRN_DOWN:
    //printf("%s\n", "We're going down!:");
    break;

    case OUR_DIRN_STOP:
    //printf("%s\n", "We're stopping!:");
    break;
    
    case OUR_DIRN_UP:
    //printf("%s\n", "We're going up!:");
    break;
    }
}
