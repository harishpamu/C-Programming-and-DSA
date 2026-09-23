/* 
* Approaches:
* 1. Iterative (Two Pointers)
* 2. Recursion
* 3. Stack
*
* Time Complexity : O(n)
*/
#include<stdio.h>
#include<string.h>

/*
* Approach 1:
* Reverse using two pointers.
*
* Start from both ends and swap characters.
*
* Time : O(n)
* Space : O(1)
*/
void reverseIterative(char* str){
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

/*
* Approach 2:
* Reverse using recursion.
*
* Keep swapping first and last
* characters until pointers meet.
*
* Time : O(n)
* Space : O(n) recursion stack
*/
void reverseRecursion(char str[], int start, int end){
    if(start >= end){
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseRecursion(str, start + 1, end - 1);
}

/*
* Approach 3:
* Reverse using stack.
*
* Push all characters.
* Pop them back into string.
*
* Time : O(n)
* Space : O(n)
*/
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
    char str1[] = "Harish";
    char str2[] = "Harish";
    char str3[] = "Harish";

    reverseIterative(str1);
    printf("Iterative : %s\n", str1);
    
    reverseRecursion(str2, 0, strlen(str2) - 1);
    printf("Recursion : %s\n", str2);
    
    reverseStack(str3);
    printf("Stack : %s\n", str3);
    return 0;
}