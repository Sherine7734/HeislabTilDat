#include "floor_light.h"



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

/**
 * 
 * 
        //State
    typedef enum floor_light {
        FL0, FL1, FL2, FL3
    } Floor_light;

    Floor_light current_floor_light;

    Floor_light current_floor_light;
    switch(current_floor_light) {
    
    case FL0:
        elevio_floorIndicator(0);
        printf("Floor light 0 i on");
        if (elevio_floorSensor() == 1){
            current_floor_light = FL1;
        }
        break;
    case FL1:
        elevio_floorIndicator(1);
        printf("Floor light 1 i on");
        if (elevio_floorSensor() == 0){
            current_floor_light = FL0;
        }
        if (elevio_floorSensor() == 2){
            current_floor_light = FL2;
        }
        break;
    case FL2:
        elevio_floorIndicator(2);
        printf("Floor light 2 i on");
        if (elevio_floorSensor() == 1){
            current_floor_light = FL1;
        }
        if (elevio_floorSensor() == 3){
            current_floor_light = FL3;
        }
        break;
    case FL3:
        elevio_floorIndicator(3);
        printf("Floor light 3 i on");
        if (elevio_floorSensor() == 2){
            current_floor_light = FL2;
        }
        break;
    
    }
*/