#include <stdio.h>
#include <stdlib.h>

static int st = 20;

int main(){
    int local = 10;

    int *heap = malloc(sizeof(int));

    printf("Stack  : %p\n",(void *)&local);
    printf("Static : %p\n",(void *)&st);
    printf("Heap   : %p\n",(void *)heap);

    free(heap);

    return 0;
}