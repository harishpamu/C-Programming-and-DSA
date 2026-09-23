#include<stdio.h>

char *my_strstr(const char *str, const char *sub){
    if(*sub == '\0'){
        return (char*)str;
    }

    while(*str){
        const char *s1 = str;
        const char *s2 = sub;

        while((*s1 == *s2) && (*s2 != '\0')){
            s1++;
            s2++;
        }

        if(*s2 == '\0'){
            return (char*)str;
        }
        str++;
    }

    return NULL;
}

int main(){
    char str[] = "Embedded Linux Driver";
    char sub[] = "Linux";

    char *ptr = my_strstr(str, sub);
    if(ptr){
        printf("Found: %s\n", ptr);
    } else{
        printf("Not Found\n");
    }

    return 0;
}
