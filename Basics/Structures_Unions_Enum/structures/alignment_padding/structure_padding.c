#include <stdio.h>

struct Test
{
    char a;   // 1 byte
              // 3 bytes padding
    int b;    // 4 bytes
};

int main()
{
    printf("Size = %zu\n", sizeof(struct Test));

    return 0;
}