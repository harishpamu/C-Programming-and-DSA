#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr = malloc(sizeof(int));
    *ptr = 999;

    int **pptr = &ptr;

    printf("%d\n", **pptr);

    free(ptr);

    return 0;
}