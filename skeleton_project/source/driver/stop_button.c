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
        
    } else {
        elevio_doorOpenLamp(0);
    }
}