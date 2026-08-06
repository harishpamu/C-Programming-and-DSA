#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
    int count;
}Stack;

void init(Stack* s){
    s->top = NULL;
    s->count = 0;
}

void push(Stack* s, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Allocation Failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;

    s->top = newNode;
    s->count++;
}

int pop(Stack* s){
    if(s->top == NULL){
        printf("Stack UnderFlow\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;

    s->top = s->top->next;
    free(temp);

    return value;
}

int peek(Stack* s){
    if(s->top == NULL){
        printf("Stack is Empty\n");
        return -1;
    }

    return s->top->data;
}

int main()
{
    Stack s;

    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top = %d\n", peek(&s));

    printf("Popped = %d\n", pop(&s));

    printf("Top = %d\n", peek(&s));

    printf("Size = %d\n", s.count);

    return 0;
}
