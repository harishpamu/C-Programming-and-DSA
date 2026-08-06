#include<stdio.h>

void *my_memcpy(void *dest, const void *src, size_t n){
    unsigned char *d = (unsigned char*)dest;
    const unsigned char *s = (const unsigned char*)src;

    while(n--){
        *d++ = *s++;
    }

    return dest;
}

int main(){
    char src[] = "Hello";
    char dest[10];

    my_memcpy(dest, src, 6);
    printf("%s\n", dest);

    return 0;
}