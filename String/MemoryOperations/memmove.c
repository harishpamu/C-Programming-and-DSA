#include<stdio.h>

/*
* Manual implementation of memmove().
*
* Unlike memcpy(), this handles overlapping memory.
*/
void *my_memmove(void *dest, const void *src, size_t n){
    unsigned char *d = (unsigned char*)dest;
    const unsigned char *s = (const unsigned char*)src;

    /*
    * If destination starts before source,
    * copy forward.
    */
    if(d < s){
        /* Forward Copy*/
        while(n--){
            *d++ = *s++;
        }
    } 
    /*
    * Overlapping case: 
    * copy backwards.
    */
    else{
        /* Backward Copy*/
        d += n;
        s += n;
        while(n--){
            *(--d) = *(--s);
        }
    }

    return dest;
}

int main(){
    char str[20] = "ABCDE";
    printf("Before : %s\n", str);
    
    my_memmove(str + 2, str, 3);
    
    /*
    A B C D E
    0 1 2 3 4

    Copy first 3 bytes to position 2

    Destination = str + 2

    Expected:
    A B A B C
    */
    printf("After : %s\n", str);
    
    return 0;
}