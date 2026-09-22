#include <stdio.h>

void idle(void){
    printf("State : IDLE\n");
}

void running(void){
    printf("State : RUNNING\n");
}

void error(void){
    printf("State : ERROR\n");
}

int main(){
    typedef void (*StateHandler)(void);

    StateHandler current_state;

    current_state = idle;
    current_state();

    current_state = running;
    current_state();

    current_state = error;
    current_state();

    return 0;
}