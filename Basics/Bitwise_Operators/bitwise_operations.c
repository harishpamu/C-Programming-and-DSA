#include<stdio.h>

void printBinary8(unsigned char num)
{
    for(int i = 7; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main(){
    unsigned int a = 5; // 0000 0101
    unsigned int b = 3; // 0000 0011
    unsigned int reg = 0;

    printf("a = %u\n", a);
    printf("b = %u\n\n", b);

    /********************************************************
    * 1. BITWISE AND (&)
    * Returns 1 only if both bits are 1
    ********************************************************/
    printf("AND(&)\n");
    printBinary8(a & b);
    printf("%u & %u = %u\n\n", a, b, a & b);
    
    /********************************************************
    * 2. BITWISE OR (|)
    * Returns 1 if either bit is 1
    ********************************************************/
    printf("OR(|)\n");
    printf("%u | %u = %u\n\n", a, b, a | b);

    /********************************************************
    * 3. BITWISE XOR (^)
    * Returns 1 when bits are different
    ********************************************************/
    printf("XOR (^)\n");
    printf("%u ^ %u = %u\n\n", a, b, a ^ b);

    /********************************************************
    * 4. BITWISE NOT (~)
    * Complements all bits
    ********************************************************/
    printf("NOT (~)\n");
    printf("~%u = %d\n\n", a, ~a); // ~a = -(a + 1)
    /********************************************************
    * 5. LEFT SHIFT (<<)
    * Multiply by 2^n
    ********************************************************/
    printf("LEFT SHIFT (<<)\n");
    printf("%u << 1 = %u\n", a, a << 1);
    printf("%u << 2 = %u\n\n", a, a << 2);

    /********************************************************
    * 6. RIGHT SHIFT (>>)
    * Divide by 2^n
    ********************************************************/   
    printf("RIGHT SHIFT (>>)\n");
    printf("20 >> 1 = %u\n", 20 >> 1);
    printf("20 >> 2 = %u\n\n", 20 >> 2);
    
    /********************************************************
    * EMBEDDED REGISTER OPERATIONS
    ********************************************************/
    
    printf("Register Operations\n");
    
    /* Set Bit 3 */
    reg |= (1 << 3);
    printf("Set Bit 3  : 0x%X\n", reg);

    /* Set Bit 5 */
    reg |= (1 << 5);
    printf("Set BIt 5  : 0x%X\n", reg);
    printBinary8(reg);
    
    /* Check bit 3 */
    if(reg & (1 << 3)){
        printf("Bit 3 is SET\n");
    }

    /* Clear bit 3 */
    reg &= ~(1 << 3);
    printf("Clear Bit 3  : 0x%X\n", reg);

    /* Toggle bit 5 */
    reg ^= (1 << 5);
    printf("Toggle Bit 5  : 0x%X\n", reg);

    /* Toggle multiple bits */
    reg ^= ((1 << 1) | (1 << 2) | (1 << 4));
    printf("Toggle 1,2,4 : 0x%X\n\n", reg);

    /********************************************************
    * ODD / EVEN CHECK
    ********************************************************/
    int num = 13;

    if(num & 1){
        printf("%d is Odd\n\n", num);
    } else{
        printf("%d is Even\n\n", num);
    }

    /********************************************************
    * POWER OF 2 CHECK
    ********************************************************/
    num = 16;
    if((num > 0) && ((num & (num - 1)) == 0)){
        printf("%d is power of 2\n\n", num);
    } else{
        printf("%d is NOT power of 2\n\n", num);
    }

    /********************************************************
    * COUNT SET BITS
    ********************************************************/
    num = 13; // 1101

    int count = 0;
    int temp = num;
    while(temp){
        count += (temp & 1);
        temp >>= 1;
    }

    printf("Set bits in %d = %d\n\n", num, count);

    /********************************************************
    * EXTRACT A BIT
    ********************************************************/
    reg = 0x2B; // 00101011

    int bit3 = (reg >> 3) & 1;
    printf("Bit 3 of 0x%X = %d\n\n", reg, bit3);

    /********************************************************
    * SWAP USING XOR
    ********************************************************/
    int x = 10;
    int y = 20;

    printf("Before Swap: x=%d y=%d\n", x, y);
    x ^= y;
    y ^= x;
    x ^= y;
    printf("After Swap : x=%d y=%d\n", x, y);

    return 0;
}