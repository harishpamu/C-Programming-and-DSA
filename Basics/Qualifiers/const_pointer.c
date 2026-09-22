#include <stdio.h>

/*--------------------------------------------------------
    * 2. int *const ptr
    *
    * Constant Pointer
    *
    * Data    -> Mutable
    * Address -> Immutable
    *
    * Allowed:
    *      *ptr = 100;
    *
    * Not Allowed:
    *      ptr = &x;
    *
    *-----------------------------------------------------
*/
int main(){
    int n1 = 10;
    int n2 = 20;

    int *const ptr = &n1;

    printf("Before: n1 = %d\n", n1);

    *ptr = 100;      // OK

    printf("After: n1 = %d\n", n1);

    // ptr = &n2;    // ERROR: Constant pointer

    return 0;
}