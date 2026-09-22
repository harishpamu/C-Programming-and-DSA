#include <stdio.h>
#include <stdlib.h>

int main(){
    // Remedy
    int *ptr = malloc(sizeof(int));
    *ptr = 100;

    free(ptr);
    ptr = NULL;

    // Situational Example
    int *dangling = malloc(sizeof(int));
    *dangling = 50;

    free(dangling);
    /*
    * Dangerous:
    * Memory already released.
    */

    // printf("%d\n", *dangling); // ERROR: Undefined Behaviour

    /*
    * should be made NULL
    */
    dangling = NULL;

    return 0;
}