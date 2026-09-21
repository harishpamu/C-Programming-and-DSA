#include "bit_tricks.h"

/* Count Set Bits */
int countSetBits(unsigned int n){
    int count = 0;

    while(n){
        n &= (n - 1);
        count ++;
    }

    return count;
}

/* Count Clear Bits */
int countClearBits(unsigned int n){
    return 32 - countSetBits(n);
}

/* Extract Rightmost Set Bit */
unsigned int extractRightMostSetBit(unsigned int n){
    /*
    * n = 1100
    * -n = ~n + 1; 0011 + 1 = 0100
    * n & (-n) = 0100
    */
    return n & (-n);   
}

/* Remove Rightmost Set Bit */
unsigned int removeRightMostSetBit(unsigned int n){
    return n & (n - 1);
}

/* Position of Rightmost Set Bit */
int rightMostSetBitPos(unsigned int n){
    int pos = 0;
    while((n & 1) == 0){
        pos++;
        n = n >> 1;
    }

    return pos;
}

/* Reverse Bits */
unsigned int reverseBits(unsigned int n){
    unsigned int rev = 0;
    for(int i = 0; i < 32; i++){
        rev = rev << 1;
        rev |= (n & 1);
        n = n >> 1;
    }

    return rev;
}

/* Binary Palindrome */
int isBinaryPalindrome(unsigned int n){
    return (n == reverseBits(reverseBits(n)));
}

/* Find Unique Element */
int findUniqueElement(int arr[], int size){
    int result = 0;
    for(int i = 0; i < size; i++){
        result ^= arr[i];
    }

    return result;
}

/* Find Missing Number */
int findMissingNumber(int arr[], int size, int n){
    int xor1 = 0;
    int xor2 = 0;

    for(int i = 0; i <= n; i++){
        xor1 ^= i;
    }

    for(int i = 0; i < size; i++){
        xor2 ^= arr[i];
    }

    return xor1 ^ xor2;
}

/* XOR Swap */
void xorSwap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/* Multiply by 2^n */
unsigned int multiplyByPower2(unsigned int n, int power){
    return n << power;
}

/* Divide by 2^n */
unsigned int divideByPower2(unsigned int n, int power){
    return n >> power;
}

/* Generate Mask */
unsigned int generateMask(int start, int width){
    return ((1U << width) - 1) << start;
}

/* Extract Bit Field */
unsigned int extractBitField(unsigned int reg, int start, int width){
    return (reg >> start) & ((1U << width) - 1);
}

/* Set Bit Field */
void setBitField(unsigned int *reg, int start, int width) {
    *reg |= generateMask(start, width);
}

/* Clear Bit Field */
void clearBitField(unsigned int *reg, int start, int width) {
    *reg &= ~generateMask(start, width);
}

/* Update Bit Field */
void updateBitField(unsigned int *reg, int start, int width, unsigned int value)
{
    *reg = (*reg & ~generateMask(start, width)) | ((value & ((1U << width)-1)) << start);
}

/* Swap Odd Even Bits */
unsigned int swapOddEvenBits(unsigned int n){
    return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}

/* Circular Left Rotation */
unsigned int rotateLeft(unsigned int n, int shift) {
    return (n << shift) | (n >> (32 - shift));
}

/* Circular Right Rotation */
unsigned int rotateRight(unsigned int n, int shift)
{
    return (n >> shift) | (n << (32 - shift));
}

void printBinary(unsigned int n){
    for(int i = 31; i >= 0; i--){
        printf("%d", (n >> i) & 1);

        if(i % 4 == 0)
            printf(" ");
    }

    printf("\n");
}