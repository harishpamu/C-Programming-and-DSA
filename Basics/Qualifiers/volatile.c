#include <stdio.h>

volatile int flag = 0;

int main(){
    printf("Waiting for flag...\n");

    while(flag == 0)
    {
        // Compiler must read flag every iteration
    }

    printf("Flag Set!\n");

    return 0;
}

/*
#define STATUS_REG (*(const volatile unsigned int *)0x40000000)

int main() {
    unsigned int status;

    status = STATUS_REG;

    printf("Staaus = %u\n", status);

    return 0;
}
*/