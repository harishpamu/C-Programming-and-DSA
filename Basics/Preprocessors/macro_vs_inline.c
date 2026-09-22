#include <stdio.h>

#define SQUARE_MACRO(x) ((x) * (x))

static inline int square_inline(int x)
{
    return x * x;
}

int main()
{
    printf("Macro  = %d\n", SQUARE_MACRO(5));
    printf("Inline = %d\n", square_inline(5));

    return 0;
}