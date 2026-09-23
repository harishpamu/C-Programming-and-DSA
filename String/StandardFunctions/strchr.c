#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "Embedded Linux";

    // Finds first occurrence of character.
    char *ptr = strchr(str, 'd');
    if(ptr){
        printf("Found at index %ld\n", ptr - str);
    }

    return 0;
}