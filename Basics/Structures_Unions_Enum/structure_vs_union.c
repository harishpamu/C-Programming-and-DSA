#include <stdio.h>

struct StructDemo{
    int i;
    char c;
};

union UnionDemo{
    int i;
    char c;
};

int main()
{
    printf("Structure Size = %zu\n", sizeof(struct StructDemo));
    printf("Union Size = %zu\n", sizeof(union UnionDemo));

    return 0;
}