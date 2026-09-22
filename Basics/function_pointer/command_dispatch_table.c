#include <stdio.h>

/*
* CLI Commands
* Protocol Hand*ers
* AT Commands
* Linux Drivers
*/

void start(void){
    printf("START\n");
}

void stop(void){
    printf("STOP\n");
}

void reset(void){
    printf("RESET\n");
}

int main()
{
    void (*commands[])(void) = {
        start,
        stop,
        reset
    };

    commands[0]();
    commands[1]();
    commands[2]();

    return 0;
}