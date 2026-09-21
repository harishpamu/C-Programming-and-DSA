#include<stdio.h>

/* Toggle a single bit */
void toggleBit(unsigned int *n, int pos){
    *n ^= (1U << pos);
}

/* Toggle multiple bits using a mask */
void toggleMultipleBits(unsigned int *n, unsigned int mask){
    *n ^= mask;
}

/* Toggle bits in a range [start, end] */
void toggleBitRange(unsigned int *n, int start, int end){
    for(int i = start; i <= end; i++){
        *n ^= (1U << i);
    }
}

/* Toggle all bits */
void toggleAllBits(unsigned int *n){
    *n ^= ~(*n);
}

/* Print binary representation */
void printBinary(unsigned int n){
    for(int i = 31; i >= 0; i--){
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main(){
    unsigned int n = 22; // 00010110

    printf("Original:\n");
    printBinary(n);

    /* Toggle bit 1 */
    toggleBit(&n, 1);
    printf("\nAfter Toggle Bit1:\n");
    printBinary(n);

    /* Toggle bit 3 */
    toggleBit(&n, 3);
    printf("\nAfter Toggle Bit3:\n");
    printBinary(n);

    /* Toggle multiple bits (1,2,4) */
    unsigned int mask = (1 << 1) | (1 << 2) | (1 << 4);
    toggleMultipleBits(&n, mask);
    printf("\nAfter Toggling Bits (1,2,4):\n");
    printBinary(n);

    /* Toggle range 5-7 */
    toggleBitRange(&n, 5, 7);
    printf("\nAfter Toggling Range (5-7):\n");
    printBinary(n);

    return 0;
}