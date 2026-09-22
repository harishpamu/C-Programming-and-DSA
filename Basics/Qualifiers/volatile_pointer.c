#include <stdio.h>

int main()
{
    volatile int value = 10;

    // Pointer to volatile data
    volatile int *ptr = &value;

    printf("%d\n", *ptr);

    *ptr = 20;

    printf("%d\n", *ptr);

    return 0;
}