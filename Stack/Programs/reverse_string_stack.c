/*
* Reverse a String Using Stack
*
* Time Complexity : O(n)
* Space Complexity: O(n)
*/
#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct Stack{
    char data[MAX];
    int top;
}Stack;

void init(Stack *s){
    s->top = -1;
}

void push(Stack* s, int ch){
    s->data[++(s->top)] = ch;
}

char pop(Stack *s){
    return s->data[s->top--];
}

int main(){
    char str[] = "EmbeddedLinux";
    Stack s;
    init(&s);
    for(int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }
    printf("Original String : %s\n", str);
    printf("Reversed String : ");
    while(s.top != -1) {
        printf("%c", pop(&s));
    }
    printf("\n");
    return 0;
}