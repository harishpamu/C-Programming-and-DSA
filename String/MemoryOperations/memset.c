/*
 * Manual implementation of memset().
 *
 * Fills memory with a byte value.
 * 
 * Common Embedded Usage
    Initialize structure:
        struct Device dev;
        memset(&dev, 0, sizeof(dev));

    Reset buffer:
        memset(buffer, 0, sizeof(buffer));

    Initialize with pattern:
        memset(buffer, 0xFF, sizeof(buffer));
 */

#include <stdio.h>

void *my_memset(void *ptr, int value, unsigned int n){
    unsigned char *p = (unsigned char *)ptr;

    while(n--){
        *p = (unsigned char)value;
        p++;
    }

    return ptr;
}

int main(){
    char buffer[10];

    my_memset(buffer, 'A', sizeof(buffer));

    printf("Buffer Contents:\n");
    for(int i = 0; i < sizeof(buffer); i++){
        printf("%c ", buffer[i]);
    }

    printf("\n");

    return 0;
}