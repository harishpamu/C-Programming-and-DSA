#include<stdio.h>

#define MAX 10
typedef struct Stack{
    int data[MAX];
    int top;
}Stack;

void init(Stack* s){
    s->top = -1;
}

int isEmpty(Stack* s){
    return s->top == -1;
}

int isFull(Stack* s){
    return s->top >= MAX - 1;
}
void push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack is Full\n");
        return;
    }

    s->data[++(s->top)] = value;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }

    return s->data[s->top--];
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }
    return s->data[s->top];
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return;
    }

    for(int i = s->top; i >= 0; i--){
        printf("%d\n", s->data[i]);
    }
}

int main()
{
    Stack s;

    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("Stack Elements:\n");
    display(&s);

    printf("\nTop Element = %d\n", peek(&s));

    printf("\nPopped Element = %d\n", pop(&s));

    printf("\nStack After Pop:\n");
    display(&s);

    return 0;
}