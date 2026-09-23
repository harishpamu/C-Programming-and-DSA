#include<stdio.h>
#include<string.h>

int main(){
    char str1[] = "Harish12";
    char str2[] = "Hari";

    // Compare first N characters.
    if(strncmp(str1, str2, 4) == 0){
        printf("First 4 are match\n");
    } else{
        printf("Not matched\n");
    }
}