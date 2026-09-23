#include <stdio.h>
#include <string.h>

int main(){
    char src[] = "Linux";
    char dest[20];

    // Copies source string to destination.
    strcpy(dest, src);
    printf("Source      : %s\n", src);
    printf("Destination : %s\n", dest);

    return 0;
}