#include <stdio.h>

int main(){
    int *ptr;

    printf("Wild Pointer Example\n");

    /*
    * Pointer declared but not initialized.
    *
    * Dangerous:
    * Contains garbage address.
    */
    //int *wildPtr;

    /* Never dereference - Dereferencing causes undefined behaviour. 
    * Uncomment print for error...
    */
    // printf("%d\n", *wildPtr);
    return 0;
}