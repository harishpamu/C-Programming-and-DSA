#include<stdio.h>

void *my_memmove(void *dest, const void *src, size_t n){
    unsigned char *d = (unsigned char*)dest;
    const unsigned char *s = (const unsigned char*)src;

    if(d < s){
        /* Forward Copy*/
        while(n--){
            *d++ = *s++;
        }
    } else{
        /* Backward Copy*/
        d += n;
        s += n;
        while(n--){
            *(--d) = *(--s);
        }
    }

    return dest;
}

int main()
{
    char str[] = "123456";

    my_memmove(str + 2, str, 4);
    printf("%s\n", str);
    
    return 0;
}