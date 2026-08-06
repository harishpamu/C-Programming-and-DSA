#include<stdio.h>
#include<string.h>

void reverseString(char* str){
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void reverseRecurssion(char str[], int start, int end){
    if(start >= end){
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseRecurssion(str, start + 1, end - 1);
}

void reverseStack(char str[]){
    int len = strlen(str);
    char stack[len];
    int top = -1;

    for(int i = 0; i < len; i++){
        stack[++top] = str[i]; 
    }

    for(int i = 0; i < len; i++){
        str[i] = stack[top--];
    }
}

int main(){
    char str[] = "Harish";

    reverseStack(str);
    printf("%s\n", str);

    return 0;
}