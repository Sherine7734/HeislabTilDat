/**
 * @file
 * @brief Implementation of which door state and door obstruction state we are in.
 *
 */

#include "door.h"

Door_State current_door_state = CLOSED;

//A function that chooses which door state we are in
/**
 * @brief Turns the door light on if the door state is open and turns the door light off if the door state is closed
 */
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

/**
 * @brief Chooses which door obstructions state we are in based on if the door is obstructed
 */

void door_obstruction(int floor){
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
