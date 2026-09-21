#include<stdio.h>

/* Clear a single bit */
void clearBit(unsigned int *n, int pos){
    *n &= ~(1U << pos);
}

/* Clear multiple bits using a mask */
void clearMultipleBits(unsigned int *n, unsigned int mask){
    *n &= ~mask;
}

/* Clear all bits */
void clearAllBits(unsigned int *n){
    *n = 0;
}

/* Clear a range of bits [start, end] */
void clearBitRange(unsigned int *n, int start, int end){
    for(int i = start; i <= end; i++){
        *n &= ~(1U << i);
    }
}

void printBinary(unsigned int n){
    for(int i = 31; i >= 0; i--){
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main(){
    unsigned int n = 1023; // 1111111111

    printf("Original:\n");
    printBinary(n);

    /* Clear bit 1 */
    clearBit(&n, 1);
    printf("\nAfter Clearing Bit 1:\n");
    printBinary(n);

    /* Clear bit 3 */
    clearBit(&n, 3);
    printf("\nAfter Clearing Bit 3:\n");
    printBinary(n);

    /* Clear multiple bits (5,6,7) */
    unsigned int mask = (1 << 5) | (1 << 6) | (1 << 7);
    clearMultipleBits(&n, mask);
    printf("\nAfter Clearing Bits (5,6,7):\n");
    printBinary(n);

    /* Clear range (8-9) */
    clearBitRange(&n, 8, 9);
    printf("\nAfter Clearing Range (8-9):\n");
    printBinary(n);


    return 0;
}