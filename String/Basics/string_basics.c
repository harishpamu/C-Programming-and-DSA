#include<stdio.h>

int main(){
    /* String stored as character array */
    char str1[] = "Embedded";

    /* String stored as pointer to string literal */
    char *str2 = "LInux";
    
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    /* Access individual characters */
    printf("First character of str1 = %c\n", str1[0]);
    printf("Second character of str2 = %c\n", str2[1]);

    return 0;
}
