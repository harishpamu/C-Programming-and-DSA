/*
 * Check Balanced Parentheses
 *
 * Time Complexity : O(n)
 * Space Complexity: O(n)
 */

#include <stdio.h>

#define MAX 100

typedef struct Stack{
    char data[MAX];
    int top;
}Stack;

void init(Stack *s){
   s->top = -1;
}

void push(Stack *s, char ch){
    s->data[++s->top] = ch;
}

char pop(Stack *s){
    return s->data[s->top--];
}

int isEmpty(Stack *s){
    return s->top == -1;
}

int isMatching(char open, char close){
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

int isBalanced(char str[]){
    Stack s;
    init(&s);

    for(int i = 0; str[i]; i++){
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '['){
            push(&s, ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(isEmpty(&s)){
                return 0;
            }

            char top = pop(&s);

            if(!isMatching(top, ch)){
                return 0;
            }
        }
    }

    return isEmpty(&s);
}

int main(){
    char expr[] = "{[()]}";

    if(isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}