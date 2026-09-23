#include<stdio.h>

char *my_strcat(char *dest, const char *src){
    char *ptr = dest;
    while(*dest != '\0'){
        dest++;
    }

    while(*src != '\0'){
        *dest++ = *src++;
    }

    *dest = '\0';

    return ptr;
}

char *my_strncat(char *dest, const char *src, int n){
    char *ptr = dest;
    while(*dest != '\0'){
        dest++;
    }

    while(n > 0 && *src != '\0'){
        *dest++ = *src++;
        n--;
    }

    *dest = '\0';

    return ptr;
}

int main(void) {
    char str1[50] = "Hello ";
    char str2[] = "Harish";
    
    my_strcat(str1, str2);
    printf("my_strcat() = %s\n", str1);

    char str3[50] = "Hello ";
    my_strncat(str3, str2, 3);
    printf("my_strncat() = %s\n", str3);

    return 0;
}