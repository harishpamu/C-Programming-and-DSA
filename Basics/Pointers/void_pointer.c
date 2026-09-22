#include <stdio.h>

int main(){
    int x = 100;
    void *vp = &x;

    printf("%d\n", *(int *)vp);

    return 0;
}