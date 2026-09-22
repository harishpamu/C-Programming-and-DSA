#include <stdio.h>

int main(){
    int x = 10;
    int *ptr = &x;

    printf("Before = %d\n", x);

    *ptr = 20;
    printf("After  = %d\n", x);

    return 0;
}