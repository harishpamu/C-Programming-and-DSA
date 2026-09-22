#include <stdio.h>

#pragma pack(1)

struct Test{
    char a;
    int b;
};

int main()
{
   printf("Size = %zu\n", sizeof(struct Test));

    return 0;
}