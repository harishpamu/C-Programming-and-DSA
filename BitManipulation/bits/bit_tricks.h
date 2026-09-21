#ifndef BIT_TRICKS_H
#define BIT_TRICKS_H

#include <stdio.h>

/* Counting */
int countSetBits(unsigned int n);
int countClearBits(unsigned int n);
int rightMostSetBitPos(unsigned int n);

/* Bit Tricks */
unsigned int extractRightMostSetBit(unsigned int n);
unsigned int removeRightMostSetBit(unsigned int n);
unsigned int reverseBits(unsigned int n);
int isBinaryPalindrome(unsigned int n);

/* XOR Problems */
int findUniqueElement(int arr[], int size);
int findMissingNumber(int arr[], int size, int n);
void xorSwap(int *a, int *b);

/* Arithmetic */
unsigned int multiplyByPower2(unsigned int n, int power);
unsigned int divideByPower2(unsigned int n, int power);

/* Bit Fields */
unsigned int extractBitField(unsigned int reg, int start, int width);
void setBitField(unsigned int *reg, int start, int width);
void clearBitField(unsigned int *reg, int start, int width);
void updateBitField(unsigned int *reg, int start, int width, unsigned int value);

/* Masks */
unsigned int generateMask(int start, int width);

/* Rotations */
unsigned int rotateLeft(unsigned int n, int shift);
unsigned int rotateRight(unsigned int n, int shift);

/* Swap Odd/Even Bits */
unsigned int swapOddEvenBits(unsigned int n);

void printBinary(unsigned int n);
#endif