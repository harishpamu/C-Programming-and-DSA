#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "Hello";
    char *ptr = str;

    while(*ptr){
        printf("%c", *ptr);
        ptr++;
    }

    printf("\n");
    return 0;
}