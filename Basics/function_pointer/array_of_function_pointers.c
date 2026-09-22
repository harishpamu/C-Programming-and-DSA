#include <stdio.h>

void add(void){
    printf("Add Operation\n");
}

void sub(void){
    printf("Subtract Operation\n");
}

void mul(void){
    printf("Multiply Operation\n");
}

int main(){
    /* Array of Function Pointers */
    void (*fp[])(void) =
    {
        add,
        sub,
        mul
    };

    fp[0]();
    fp[1]();
    fp[2]();

    return 0;
}