#include<stdio.h>

int my_strlen(const char *str){
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }

    return count;
}

int main(){
    char str[] = "Harish";
    printf("length of the string: %d\n", my_strlen(str));

    return 0;
}