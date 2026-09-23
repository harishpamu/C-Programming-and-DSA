#include <stdio.h>

int main(){
    char str[] = "100 200";

    int a, b;

    // Reads formatted data from string.
    sscanf(str, "%d %d",&a, &b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}