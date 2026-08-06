#include<stdio.h>

int my_strcmp(const char *str1, const char *str2){
    while((*str1 != '\0') && (*str2 != '\0')){
        if(*str1 != *str2){
            return (*str1 - *str2);
        }

        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int my_strncmp(const char* str1, const char *str2, int n){
    while(n > 0){
        if((*str1 == '\0') || (*str2 == '\0')){
            break;
        }

        if(*str1 != *str2){
            return (*str1 - *str2);
        }

        str1++;
        str2++;
        n--;
    }

    if(n == 0){
        return 0;
    }

    return (*str1 - *str2);
}

int main(void){
    printf("strcmp(ABC,ABC) = %d\n", my_strcmp("ABC","ABC"));
    printf("strcmp(ABC,ABD) = %d\n", my_strcmp("ABC","ABD"));
    printf("strncmp(HELLO,HELP,3) = %d\n", my_strncmp("HELLO","HELP",3));
    printf("strncmp(HELLO,HELP,4) = %d\n", my_strncmp("HELLO","HELP",4));
    return 0;
}