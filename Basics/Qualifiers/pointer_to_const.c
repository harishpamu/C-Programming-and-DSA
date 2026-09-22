#include <stdio.h>

/*---------------------------------------------------------
    * Pointer To Constant
    *
    * Data    -> Immutable
    * Address -> Mutable
    *
    * Allowed:
    *      ptr = &x;
    *
    * Not Allowed:
    *      *ptr = 100;
    *
    *---------------------------------------------------------
*/
int main(){
    int n1 = 10;
    int n2 = 20;

    const int *ptr = &n1;

    printf("n1 = %d\n", n1);

    // *ptr = 100;   // ERROR: Cannot modify data through ptr

    ptr = &n2;       // OK: Pointer can point elsewhere

    printf("Now ptr points to n2 = %d\n", *ptr);

    return 0;
}