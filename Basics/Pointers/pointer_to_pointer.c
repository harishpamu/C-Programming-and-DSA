#include <stdio.h>

int main(){
    int x = 10;
    int *ptr = &x;
    int **pptr = &ptr;
    
    printf("x = %d\n", x);
    printf("*ptr = %d\n", *ptr);
    printf("**pptr = %d\n", **pptr);

    return 0;
}