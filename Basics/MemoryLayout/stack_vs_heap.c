#include <stdio.h>
#include <stdlib.h>

int main(){
    int local = 10;                 /* Stack */

    int *heap = malloc(sizeof(int));/* Heap */

    *heap = 20;

    printf("Stack = %d\n", local);
    printf("Heap  = %d\n", *heap);

    free(heap);

    return 0;
}