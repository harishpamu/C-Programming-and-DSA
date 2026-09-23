#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "Harish";
    printf("%s\n", str);

    /*
    * sizeof()
    * Counts complete array size including '\0'
    */
    printf("sizeof(str) = %zu\n", sizeof(str));

    /*
    * strlen()
    * Counts only visible characters
    */
    printf("strlen(str) = %zu\n", strlen(str));

    return 0;
}