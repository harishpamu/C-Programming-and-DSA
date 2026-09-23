#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "Embedded Linux";

    // Finds last occurrence of character
    char *ptr = strrchr(str, 'd');
    if(ptr){
        printf("Last Occurance index: %ld\n", ptr - str);
    }

    return 0;
}