#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
//#include "driver/elevio.h"
#include "driver/floor_light.h"
#include "driver/stop_button.h"
#include "driver/door.h"
#include "driver/motor.h"
#include "driver/start_up.h"



int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_DOWN);
    int floor = elevio_floorSensor();
    start_up(floor);//HELP!!!!!!!!! How do we get the elevator to start going down?????


    while(1){
        printf("%d\n", floor);
        floor = elevio_floorSensor();
        setFloorLight(floor); //*
        activate_stop_light(); //*
        open_door_when_stop(floor); //*
        keep_door_open_when_not_stop(floor);//*
        door_state_implementation();//*
        door_obstruction();//*
        //printf("%s\n", "StopButton:");//*
        //printf("%d\n", elevio_stopButton()); //*

        if(floor == 0){
            elevio_motorDirection(DIRN_UP);
        }

        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }


        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            activate_stop_light();
            //break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}
