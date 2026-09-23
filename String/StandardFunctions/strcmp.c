#include<stdio.h>
#include<string.h>

int main(){
    char str1[] = "Harish";
    char str2[] = "Harish";
    // char str2[] = "Pamu";

    // strcmp(s1, s2) compares two strings.
    if(strcmp(str1, str2) == 0){
        printf("Strings are Equal\n");
    } else{
        printf("Strings are different\n");
    }

    return 0;
}