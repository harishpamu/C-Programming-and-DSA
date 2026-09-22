#include<stdio.h>

/*All members share same memory.
 */
union Data {
    int i;
    float f;
    char c;
};

int main()
{
    union Data data;

    data.i = 100;
    printf("i = %d\n", data.i);

    data.f = 10.5;
    printf("f = %.2f\n", data.f);

    return 0;
}