#include <stdio.h>

/* Set a single bit */
void setBit(unsigned int *n, int pos){
    *n |= (1U << pos);
}

/* Set multiple bits using a mask */
void setMultipleBits(unsigned int *n, unsigned int mask){
    *n |= mask;
}

/* Set all bits */
void setAllBits(unsigned int *n){
    *n = ~0U;
}

/* Set bits in a range [start, end] */
void setBitRange(unsigned int *n, int start, int end){
    for(int i = start; i <= end; i++){
        *n |= (1U << i);
    }
}

/* Print binary representation */
void printBinary(unsigned int n){
    for(int i = 31; i >= 0; i--){
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

/* Print positions of all set bits */
void printSetBitPositions(unsigned int n)
{
    printf("Set bit positions: ");

    for(int i = 0; i < 32; i++)
    {
        if((n >> i) & 1)
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}

/* Extract the actual bit masks - Instead of positions, you can extract the set-bit values */
void printSetBitValues(unsigned int n)
{
    printf("Set bit values: ");

    for(int i = 0; i < 32; i++)
    {
        if(n & (1U << i))
        {
            printf("%u ", (1U << i));
        }
    }

    printf("\n");
}

/*
* Efficient extraction of set bits
* n & (-n) extracts the rightmost set bit
* n &= (n-1) removes the rightmost set bit
*/
void extractSetBits(unsigned int n){
    printf("Extracted Set Bits: ");
    while(n)
    {
        unsigned int bit = n & (-n);
        printf("%u ", bit);
        n &= (n - 1);
    }
    printf("\n");
}

int main()
{
    unsigned int n = 0;

    printf("Initial Value:\n");
    printBinary(n);

    /* Set bit 2 */
    setBit(&n, 2);
    printf("\nAfter Setting Bit 2:\n");
    printBinary(n);

    /* Set bit 4 */
    setBit(&n, 4);
    printf("\nAfter Setting Bit 4:\n");
    printBinary(n);

    /* Set multiple bits (1,3,5) */
    unsigned int mask = (1 << 1) | (1 << 3) | (1 << 5);
    setMultipleBits(&n, mask);
    printf("\nAfter Setting Multiple Bits (1,3,5):\n");
    printBinary(n);

    /* Set range 6 to 8 */
    setBitRange(&n, 6, 8);
    printf("\nAfter Setting Range (6-8):\n");
    printBinary(n);


    printSetBitPositions(n);
    printSetBitValues(n);
    extractSetBits(n);
    return 0;
}