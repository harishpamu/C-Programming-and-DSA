#include <stdio.h>

#define SQUARE(x) ((x) * (x))
// #define SQUARE(x) x*x

int main(){
    int n = 5;

    printf("Square = %d\n", SQUARE(n));
    printf("Square = %d\n", SQUARE(2 + 3));

    return 0;
}