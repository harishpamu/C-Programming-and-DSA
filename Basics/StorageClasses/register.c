/*
 * Register - Suggests compiler store variable
 * in CPU register for faster access.
 * 
 * Mostly ignored by GCC/Clang optimizers.
 */

#include <stdio.h>

int main()
{
    register int i;
    // register int x = 10;
    // printf("%p", &x); // ERROR
    /* 
    * ERROR: 
    * Because register variables may reside in CPU registers instead of RAM.
    * No valid memory address exists.
    */
    for(i = 0; i < 5; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}