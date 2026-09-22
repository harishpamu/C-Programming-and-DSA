#include <stdio.h>

/*---------------------------------------------------------
    *
    * 4. const int *const ptr
    *
    * Constant Pointer To Constant
    *
    * Data    -> Immutable
    * Address -> Immutable
    *
    * Allowed:
    *      Read only
    *
    * Not Allowed:
    *      *ptr = 100;
    *      ptr = &x;
    *
    *--------------------------------------------------------
*/
int main(){
    int n1 = 10;
    int n2 = 20;

    const int *const ptr = &n1;

    printf("n1 = %d\n", *ptr);

    // *ptr = 100;   // ERROR: Data is constant

    // ptr = &n2;    // ERROR: Pointer is constant

    return 0;
}