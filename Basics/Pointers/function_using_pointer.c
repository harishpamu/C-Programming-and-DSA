#include <stdio.h>

void update(int *num) {
    *num = 100;
}

int main(){
    int x = 10;
    update(&x);

    printf("%d\n", x);

    return 0;
}