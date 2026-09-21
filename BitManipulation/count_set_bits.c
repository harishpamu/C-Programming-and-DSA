#include <stdio.h>

/* Count set bits */
void countSetBits(unsigned int n){
    int count = 0;

    while(n){
        n &= (n - 1);
        count++;
    }

    printf("Set Bits Count = %d\n", count);
}

int main(){
    unsigned int n = 22; // 00010110
    countSetBits(n);

    return 0;
}