/*
 * Sort Stack Using Temporary Stack
 *
 * Time Complexity : O(n²)
 * Space Complexity: O(n)
 */

#include <stdio.h>

#define MAX 100

typedef struct{
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack* s){
    return s->top == -1;
}

int isFull(Stack* s){
    return s->top >= MAX - 1;
}

void push(Stack *s, int value){
    if(isFull(s)){
        printf("Stack is Full\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    return s->data[s->top];
}
/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
void sortStack(Stack *s){
    Stack temp;
    init(&temp);

    // Loop until all elements are cleared from the original stack
    while(!isEmpty(s)){
        // Remove the top element to find its correct spot in temp
        int current = pop(s);

        // Move larger elements from temp back to s to make room for current
        while(!isEmpty(&temp) && peek(&temp) > current){
            push(s, pop(&temp));
        }

        // Place current into its correct sorted position inside temp
        push(&temp, current);
    }

    // Move everything back from temp to s to reverse into ascending order
    while(!isEmpty(&temp)){
        push(s, pop(&temp));
    }
}

int main(){
    Stack s;
    init(&s);

    push(&s, 30);
    push(&s, 10);
    push(&s, 40);
    push(&s, 20);

    sortStack(&s);

    printf("Sorted Stack:\n");
    while(!isEmpty(&s)){
        printf("%d\n", pop(&s));
    }

    return 0;
}