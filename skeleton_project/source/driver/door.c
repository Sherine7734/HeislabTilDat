#include "door.h"

extern Door_State current_door_state = CLOSED;

//A function that chooses which door state we are in
void door_state_implementation(void){
    switch(current_door_state){
    case CLOSED:
    elevio_doorOpenLamp(0);
    break;
    case OPEN:
    elevio_doorOpenLamp(1);
    break;
    }
    
}
