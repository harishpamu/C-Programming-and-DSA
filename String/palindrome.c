#include<stdio.h>
#include<string.h>

int isPalindrome(char str[]){
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end){
        if(str[start] != str[end]){
            return 0;
        }

        start++;
        end--;
    }
    return 1;
}

int main(){
    char str[] = "madam";

    if(isPalindrome(str)){
        printf("Palindrome\n");
    } else{
        printf("Not Palindrome\n");
    }

    return 0;
}