#include<stdio.h>

struct Point{
    int x;
    int y;
};

struct Point createPoint(){
    struct Point p = {
        .x = 10,
        .y = 20
    };
    return p;
}

int main(){
    struct Point p = createPoint();

    printf("(%d %d)\n", p.x, p.y);

    return 0;
}