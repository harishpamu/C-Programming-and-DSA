#include<stdio.h>

enum Day{
    SUN,
    MON,
    TUE,
    WED
};

int main(){
    enum Day today = MON;
    printf("MON = %d\n", today); // MON = 1

    return 0;
}