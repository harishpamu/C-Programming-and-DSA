#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "Hi, How are You?";
    char *ptr = strstr(str, "How");

    if(ptr){
        printf("Substring found: %s\n", ptr);
    }

    return 0;
}