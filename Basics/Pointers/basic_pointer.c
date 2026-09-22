#include <stdio.h>

int main(){
    int x = 10;
    int *ptr = &x;

    printf("x    = %d\n", x);
    printf("&x   = %p\n", (void *)&x);
    printf("ptr  = %p\n", (void *)ptr);
    printf("*ptr = %d\n", *ptr);

    return 0;
}