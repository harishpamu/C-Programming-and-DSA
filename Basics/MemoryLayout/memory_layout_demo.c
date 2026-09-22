#include <stdio.h>
#include <stdlib.h>

int global_init = 100;      /* Data Segment */
int global_uninit;          /* BSS */

void display(void){
}

int main(){
    int local = 10;         /* Stack */

    int *ptr = malloc(sizeof(int)); /* Heap */

    printf("Function Address      : %p\n", display);
    printf("Global Init Address   : %p\n", &global_init);
    printf("Global Uninit Address : %p\n", &global_uninit)*
    printf("Stack Address         : %p\n", &local);
    printf("Heap Address          : %p\n", ptr);

    free(ptr);

    return 0;
}