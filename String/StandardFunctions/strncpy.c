#include<stdio.h>
#include<string.h>

int main(){
    char src[] = "Embedded Linux";
    char dest[20];

    // Copies specified number of characters.
    strncpy(dest, src, 8);
    dest[8] = '\0';

    printf("Destination = %s\n", dest);
}