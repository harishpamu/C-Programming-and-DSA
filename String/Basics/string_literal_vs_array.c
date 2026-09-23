#include<stdio.h>

int main(){
    char arr[] = "Hello";
    char *ptr = "World";

    /* Allowed */
    arr[0] = 'h';

    printf("Array String : %s\n", arr);
    printf("Literal String : %s\n", ptr);

    /*
    * Not allowed:
    *
    * ptr[0] = 'w';
    *
    * String literals are usually stored in
    * read-only memory.
    */
    // ptr[0] = 'w';
}