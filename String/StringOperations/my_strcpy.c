#include<stdio.h>

char *my_strcpy(char *dest, const char *src){
    char *ptr = dest;

    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    return ptr;
}

char *my_strncpy(char *dest, const char* src, int n){
    char *ptr = dest;
    while(n > 0 && *src != '\0'){
        *dest++ = *src++;
        n--;
    }

    while(n > 0){
        *dest++ = '\0';
        n--;
    }

    return ptr;
}

int main(){
    char buffer1[20];
    char buffer2[20];

    // Testing my_strcpy
    my_strcpy(buffer1, "Hello");
    printf("strcpy result: %s\n", buffer1);

    // Testing my_strncpy with padding
    my_strncpy(buffer2, "Hi am Harish", 20);
    printf("strncpy result: %s\n", buffer2);

    // Verifying padding: the 4th char (index 3) must be '\0'
    if (buffer2[12] == '\0') {
        printf("Padding works perfectly!\n");
    }

    return 0;
}