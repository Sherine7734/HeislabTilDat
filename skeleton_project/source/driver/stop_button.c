#include "stop_button.h"

void activate_stop_light(void) {
    if (elevio_stopButton() == 1) {
        printf("%s\n", "Stop lamp on");
        elevio_stopLamp(1);
    } 
    if (elevio_stopButton() == 0) {
        printf("%s\n", "Stop lamp off");
        elevio_stopLamp(0);
    }
}

void open_door_when_stop(int floor){
    if ((floor != -1) && (elevio_stopButton() == 1)) {
        elevio_doorOpenLamp(1);
        
    }
}

Stop_Button_State current_stop_button_state  = STOP0;

void keep_door_open_when_not_stop(int floor){
    

    switch(current_stop_button_state) {
    
    case STOP0:
        printf("%s\n", "In STOP0");
        if (elevio_stopButton()==1) {
            current_stop_button_state=STOP1;
        }
        break;
    case STOP1:
        printf("%s\n", "In STOP1");
        elevio_motorDirection(DIRN_STOP);
        if ((elevio_stopButton()==0)  && (floor != -1)){
            printf("%s\n", "Timer has started");
            elevio_doorOpenLamp(1);
            sleep(3);
            elevio_doorOpenLamp(0);
            //fix direction after stop
            printf("%s\n", "Timer has ended");
            current_stop_button_state=STOP0;
        } else if (floor == -1) {
            elevio_doorOpenLamp(0);
        }
        break;
    
    }
}

/*
if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            activate_stop_light();}

*/