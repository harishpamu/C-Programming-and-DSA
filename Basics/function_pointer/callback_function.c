#include <stdio.h>

/* callback: A callback is a function passed as an argument to another function. */
void buttonPressed(void){
    printf("Button Interrupt Occurred\n");
}

/* Function accepts another function */
void registerCallback(void (*callback)(void)){
    printf("Callback Registered\n");

    callback();
}

int main(){
    registerCallback(buttonPressed);

    return 0;
}