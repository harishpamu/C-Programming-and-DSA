#include <stdio.h>

/*
    - const → Software cannot write.
    - volatile → Hardware may update it anytime.
*/

int main(){
    // Read-only for software, changeable by hardware
    const volatile int status_reg = 1;

    printf("Status = %d\n", status_reg);

    // status_reg = 5; // ERROR

    return 0;
}