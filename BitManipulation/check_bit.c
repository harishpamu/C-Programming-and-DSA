/* check_bit.c */

#include <stdio.h>

/* Check whether a specific bit is set */
void checkBit(unsigned int n, int pos)
{
    if (n & (1U << pos))
        printf("Bit %d is SET\n", pos);
    else
        printf("Bit %d is NOT SET\n", pos);
}

/* Extract bit value (0 or 1) */
void extractBit(unsigned int n, int pos)
{
    printf("Bit %d Value = %d\n", pos, (n >> pos) & 1);
}

/* Check if all bits in mask are set */
void checkAllBits(unsigned int n, unsigned int mask)
{
    if ((n & mask) == mask)
        printf("All mask bits are SET\n");
    else
        printf("All mask bits are NOT SET\n");
}

/* Check if any bit in mask is set */
void checkAnyBit(unsigned int n, unsigned int mask)
{
    if (n & mask)
        printf("At least one mask bit is SET\n");
    else
        printf("No mask bit is SET\n");
}

/* Print positions of all set bits */
void printSetBitPositions(unsigned int n)
{
    printf("Set Bit Positions: ");

    for(int i = 0; i < 32; i++)
    {
        if((n >> i) & 1)
            printf("%d ", i);
    }

    printf("\n");
}

/* Print actual set bit values */
void printSetBitValues(unsigned int n)
{
    printf("Set Bit Values: ");

    for(int i = 0; i < 32; i++)
    {
        if(n & (1U << i))
            printf("%u ", (1U << i));
    }

    printf("\n");
}

/* Count set bits */
void countSetBits(unsigned int n){
    int count = 0;
    while(n){
        n &= (n - 1);
        count++;
    }

    printf("Set Bit Count = %d\n", count);
}

/* Check Odd or Even */
void checkOddEven(unsigned int n){
    if(n & 1)
        printf("%u is ODD\n", n);
    else
        printf("%u is EVEN\n", n);
}

/* Check Power of 2 */
void checkPowerOfTwo(unsigned int n){
    if(n > 0 && ((n & (n - 1)) == 0))
        printf("%u is Power of 2\n", n);
    else
        printf("%u is NOT Power of 2\n", n);
}

int main(){
    unsigned int n = 22;   // 00010110

    unsigned int mask = (1 << 1) | (1 << 2) | (1 << 4);

    printf("n = %u\n\n", n);

    /* Check individual bits */
    checkBit(n, 1);
    checkBit(n, 3);

    printf("\n");

    /* Extract bit values */
    extractBit(n, 1);
    extractBit(n, 3);

    printf("\n");

    /* Check mask bits */
    checkAllBits(n, mask);
    checkAnyBit(n, mask);

    printf("\n");

    /* Print all set bits */
    printSetBitPositions(n);
    printSetBitValues(n);

    printf("\n");

    /* Other checks */
    countSetBits(n);
    checkOddEven(n);
    checkPowerOfTwo(n);

    return 0;
}