#include <stdio.h>

/* Print binary representation */
void printBinary(unsigned int n){
    for(int i = 31; i >= 0; i--){
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

/*
 * Swap two bits at positions p1 and p2
 */
void swapBits(unsigned int *n, int p1, int p2)
{
    int bit1 = (*n >> p1) & 1;
    int bit2 = (*n >> p2) & 1;

    /* If bits are different, toggle both */
    if(bit1 != bit2)
    {
        *n ^= (1U << p1);
        *n ^= (1U << p2);
    }
}

int main()
{
    unsigned int n = 22; // 00010110

    printf("Original:\n");
    printBinary(n);

    /* Swap bit1 and bit4 */
    swapBits(&n, 1, 4);

    printf("\nAfter Swapping Bit1 and Bit4:\n");
    printBinary(n);

    return 0;
}