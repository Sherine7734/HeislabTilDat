#include "door.h"

Door_State current_door_state = CLOSED;

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

Obstruction_State current_obstruction_state = NOTOBSTRUCT;

void door_obstruction(void){
    switch(current_obstruction_state){
    case NOTOBSTRUCT:
    if (elevio_obstruction() == 1){
        current_obstruction_state = OBSTRUCT;
    }
    break;
    case OBSTRUCT:
    if (elevio_obstruction() == 0){
        if(current_door_state == OPEN){
            sleep(3);
            current_door_state = CLOSED;
            current_obstruction_state = NOTOBSTRUCT;
        }
        current_obstruction_state = NOTOBSTRUCT;
    }
    break;
    }

}
