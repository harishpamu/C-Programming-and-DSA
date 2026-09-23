#include<stdio.h>
#include<string.h>

int main(){
    char dest[50] = "Hello ";

    // Appends specified characters.
    strncat(dest, "WorldLinux", 5);
    printf("%s\n", dest);

    return 0;
}