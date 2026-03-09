/**
 * @file
 * @brief Sets floorlight to the correct floor.
 *
 */

#include "floor_light.h"

/**
 * @brief Checks what floor we are on, and if we are in the same floor as the indicator the floorlight turns on
 * 
 * @param[in] floor Gives what floor we are on from a floor sensor
 */

void setFloorLight(int floor){
    if (floor == 0) {
        //printf("%s\n", "Floor light 0");
        elevio_floorIndicator(0);
    } else if (floor == 1) {
        //printf("%s\n", "Floor light 1");
        elevio_floorIndicator(1);
    } else if (floor == 2) {
        //printf("%s\n", "Floor light 2");
        elevio_floorIndicator(2);
    } else if (floor == 3) {
        //printf("%s\n", "Floor light 3");
        elevio_floorIndicator(3);
    } else if (floor == -1) {
        //printf("%s\n", "In between");
    }
}

