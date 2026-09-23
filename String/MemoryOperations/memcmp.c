/*
* Manual implementation of memcmp().
*
* Compares memory byte by byte.

    0   -> Equal
    <0  -> First mismatch in ptr1 is smaller
    >0  -> First mismatch in ptr1 is greater
*/
#include<stdio.h>

int my_memcmp(const void *ptr1, const void *ptr2, unsigned int n){
    const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    while(n--){
        if(*p1 != *p2){
            return *p1 - *p2;
        }

        p1++;
        p2++;
    }

    return 0;
}

int main(){
    char str1[] = "Linux";
    char str2[] = "Linux";
    char str3[] = "linux";

    printf("str1 vs str2 = %d\n", my_memcmp(str1, str2, 5));
    printf("str1 vs str3 = %d\n", my_memcmp(str1, str3, 5));
    return 0;
}