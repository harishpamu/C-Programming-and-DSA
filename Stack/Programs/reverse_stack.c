#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
}Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top--];
}

int peek(Stack* s) {
    return s->arr[s->top];
}

void reverseStack(Stack* s) {
    Stack aux;
    init(&aux);

    // move all elements to auxiliary stack
    while (!isEmpty(s)) {
        push(&aux, pop(s));
    }

    // replace original stack with auxiliary
    *s = aux;
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return;
    }

    printf("--- Stack ---\n");
    for(int i = s->top; i >= 0; i--){
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    Stack s;
    init(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    display(&s);

    reverseStack(&s);
    display(&s);

    return 0;
}