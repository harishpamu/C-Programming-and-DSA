#include "bit_tricks.h"

int main()
{
    unsigned int n = 22;

    printf("Original Number : %u\n", n);
    printBinary(n);

    printf("\nCount Set Bits = %d\n", countSetBits(n));
    printf("Count Clear Bits = %d\n", countClearBits(n));

    printf("\nExtract Rightmost Set Bit:\n");
    printBinary(extractRightMostSetBit(n));
    printf("Value = %u\n", extractRightMostSetBit(n));

    printf("\nRemove Rightmost Set Bit:\n");
    printBinary(removeRightMostSetBit(n));
    printf("Value = %u\n", removeRightMostSetBit(n));

    printf("\nRightmost Set Bit Position = %d\n", rightMostSetBitPos(n));

    printf("\nReverse Bits:\n");
    printBinary(reverseBits(n));
    printf("Value = %u\n", reverseBits(n));

    int arr[] = {1,2,3,2,1};
    printf("\nUnique Element = %d\n", findUniqueElement(arr,5));

    int arr2[] = {1,2,3,5};
    printf("Missing Number = %d\n", findMissingNumber(arr2,4,5));

    int a = 10;
    int b = 20;
    printf("\nBefore XOR Swap:\n");
    printf("a = %d b = %d\n", a, b);

    xorSwap(&a, &b);
    printf("After XOR Swap:\n");
    printf("a = %d b = %d\n", a, b);

    printf("\nMultiply By 2^2:\n");
    printBinary(multiplyByPower2(5,2));
    printf("Value = %u\n", multiplyByPower2(5,2));

    printf("\nDivide By 2^2:\n");
    printBinary(divideByPower2(20,2));
    printf("Value = %u\n", divideByPower2(20,2));

    unsigned int reg = 0;
    printf("\nInitial Register:\n");
    printBinary(reg);

    setBitField(&reg, 2, 3);
    printf("\nAfter SetBitField(start=2,width=3):\n");
    printBinary(reg);
    printf("Value = %u\n", reg);

    clearBitField(&reg, 2, 3);
    printf("\nAfter ClearBitField(start=2,width=3):\n");
    printBinary(reg);
    printf("Value = %u\n", reg);

    updateBitField(&reg, 2, 3, 5);
    printf("\nAfter UpdateBitField(start=2,width=3,value=5):\n");
    printBinary(reg);
    printf("Value = %u\n", reg);

    printf("\nExtract Bit Field:\n");
    printf("Value = %u\n", extractBitField(reg,2,3));

    printf("\nGenerated Mask(start=4,width=3):\n");
    printBinary(generateMask(4,3));
    printf("Value = %u\n", generateMask(4,3));

    printf("\nSwap Odd Even Bits (10):\n");
    printBinary(swapOddEvenBits(10));
    printf("Value = %u\n", swapOddEvenBits(10));

    printf("\nRotate Left (10, 2):\n");
    printBinary(rotateLeft(10,2));
    printf("Value = %u\n", rotateLeft(10,2));

    printf("\nRotate Right (10, 2):\n");
    printBinary(rotateRight(10,2));
    printf("Value = %u\n", rotateRight(10,2));

    return 0;
}