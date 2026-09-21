#include<stdio.h>

/* Check power of 2 */
void checkPowerOfTwo(unsigned int n)
{
    if(n > 0 && (n & (n - 1)) == 0)
        printf("%u is Power of 2\n", n);
    else
        printf("%u is NOT Power of 2\n", n);
}

int main(){
    unsigned int n = 22; // 00010110
    checkPowerOfTwo(n);

    return 0;
}