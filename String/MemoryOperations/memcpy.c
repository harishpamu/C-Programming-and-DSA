#include<stdio.h>

/*
* Manual implementation of void *memcpy(void *dest, const void *src, size_t n): 
* Copies 'n' bytes from source to destination.
*
* Important:
* memcpy() does NOT handle overlapping memory.
*/
void *my_memcpy(void *dest, const void *src, size_t n){
    unsigned char *d = (unsigned char*)dest;
    const unsigned char *s = (const unsigned char*)src;

    /*
    * Copy byte by byte
    */
    while(n--){
        *d++ = *s++;
    }

    return dest;
}

int main(){
    char src[] = "Hello";
    char dest[10];

    my_memcpy(dest, src, sizeof(src));
    
    printf("Source : %s\n", src);
    printf("Destination : %s\n", dest);

    return 0;
}