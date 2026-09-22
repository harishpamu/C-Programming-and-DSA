#include <stdio.h>

struct Test{
    char c; // 4
    int i; // 4
    short s; // 4
};

int main()
{
    printf("Size = %zu\n", sizeof(struct Test));

    return 0;
}