#include <stdio.h>

typedef int (*Operation)(int, int);

int add(int a, int b)
{
    return a + b;
}

int main()
{
    Operation op = add;

    printf("%d\n", op(10, 20));
    
    return 0;
}