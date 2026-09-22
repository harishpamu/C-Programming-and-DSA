#include <stdio.h>

/*
 * Used heavily in:
    - Linux Kernel
    - Drivers
    - Object-Oriented Style C
*/
typedef struct{
    int (*operation)(int, int);
}Calculator;

int add(int a, int b){
    return a + b;
}

int main(){
    Calculator calc;

    calc.operation = add;

    printf("Result = %d\n", calc.operation(10, 20));

    return 0;
}