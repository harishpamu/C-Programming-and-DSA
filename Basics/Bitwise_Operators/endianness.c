#include <stdio.h>
/*
 * Endianness:
 * Determines how multi-byte data is stored in memory.
 *
 * Little Endian:
 * LSB stored at lowest address.
 *
 * Big Endian:
 * MSB stored at lowest address.
 *
 * Time Complexity  : O(1)
 * Space Complexity : O(1)
 */

int isLittleEndian(void){
    unsigned int num = 1;
    return *((char *)&num) == 1;
}

int main(){
    if(isLittleEndian()){
        printf("Little Endian\n");
    } else{
        printf("Big Endian\n");
    }
    printf("Proof:\n");

    unsigned int num = 0x12345678;
    unsigned char *ptr = (unsigned char *)&num;

    printf("Number = 0x%X\n", num);

    printf("Memory Layout:\n");
    for(int i = 0; i < sizeof(num); i++){
        printf("Byte %d = 0x%02X\n", i, ptr[i]);
    }

    /*
     * Extract MSB and LSB using bit operations
     */
    unsigned char lsb = num & 0xFF;
    unsigned char msb = (num >> 24) & 0xFF;

    printf("\nLSB (Least Significant Byte) = 0x%02X\n", lsb);
    printf("MSB (Most Significant Byte)  = 0x%02X\n", msb);
    printf("\nLittle Endian : LSB stored at lowest address.\n");
    printf("Big Endian    : MSB stored at lowest address.\n");

    if(ptr[0] == lsb){
        printf("\nSystem is Little Endian\n");
        printf("Lowest Address contains LSB (0x%02X)\n", ptr[0]);
    } else{
        printf("\nSystem is Big Endian\n");
        printf("Lowest Address contains MSB (0x%02X)\n", ptr[0]);
    }

    return 0;
}