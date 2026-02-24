#include "motor.h"

MotorDirection current_motor_dir_state = DIRN_DOWN;

//A function that chooses which motor direction state we are in
void motor_dir_state_implementation(void){
    switch(current_motor_dir_state){
    case DIRN_DOWN:
    break;

    case DIRN_STOP:
    break;
    
    case DIRN_UP:
    break;
    }
}