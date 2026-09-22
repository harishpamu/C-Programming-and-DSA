#include <stdio.h>

// Largest member decides union size.
union Data{
    int i;
    float f;
    double d;
};

int main(){

    printf("Size : %zu\n", sizeof(union Data));
    return 0;
}