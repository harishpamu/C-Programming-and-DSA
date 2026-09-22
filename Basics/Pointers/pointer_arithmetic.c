#include <stdio.h>

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    /*
    * Array Memory Layout
    *
    * Address     Value
    * -------     -----
    * 1000         10
    * 1004         20
    * 1008         30
    * 1012         40
    * 1016         50
    *
    * Array name stores address of first element.
    *
    * arr == &arr[0]
    */

    int *p = arr;
    /*
    * p points to first element.
    *
    *      p
    *      |
    *      v
    * +----+----+----+----+----+
    * | 10 | 20 | 30 | 40 | 50 |
    * +----+----+----+----+----+
    */
    printf("arr      = %p\n", (void *)arr);
    printf("&arr[0]  = %p\n", (void *)&arr[0]);

    printf("\nBefore Increment:\n");
    printf("*p = %d\n", *p);

    /*
    * Pointer Arithmetic
    *
    * Since p is int*
    *
    * p++
    *
    * moves by sizeof(int)
    *
    * Example:
    * 1000 -> 1004
    */
    p++;

    printf("\nAfter Increment:\n");
    printf("*p = %d\n", *p);

    /*
    * Array name is not modifiable.
    * arr++;   // ERROR
    * Reason:
    * Array name is a constant address.
    *
    * Pointer can move.
    * p++;     // OK
    */

    return 0;
}