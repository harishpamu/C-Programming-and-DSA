/*
The minStack - is a clever trick used to solve a classic design problem: 
how to find the smallest number in a stack instantly without searching through all the elements.

In a normal stack, if you want to find the minimum value, 
you have to look at every single number inside it. 
This takes O(N) time, where N is the number of elements. 
By pairing your primary stack with a secondary 
data structure—the minStack—you can find the minimum value in O(1) constant time.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int topIndex;
} MinStack;

// Initialize the stack
void init(MinStack *s) {
    s->topIndex = -1;
}

// Check if stack is empty
bool isEmpty(MinStack *s) {
    return s->topIndex == -1;
}

// Check if stack is full
bool isFull(MinStack *s) {
    return s->topIndex >= MAX - 1;
}

// Push value onto stack
void push(MinStack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }

    // Move pointer first, then insert data
    s->topIndex++;
    s->stack[s->topIndex] = value;

    // Update minStack
    if (s->topIndex == 0) {
        s->minStack[s->topIndex] = value;
    } else {
        int currentMin = s->minStack[s->topIndex - 1];
        s->minStack[s->topIndex] = (value < currentMin) ? value : currentMin;
    }
}

// Pop top element
void pop(MinStack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    s->topIndex--;
}

// Get the actual top element
int top(MinStack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1; 
    }

    return s->stack[s->topIndex];
}

// Get the minimum element
int getMin(MinStack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No minimum value.\n");
        return -1; 
    }

    return s->minStack[s->topIndex];
}

int main() {
    MinStack s;
    init(&s);

    push(&s, 5);
    push(&s, 2);
    push(&s, 8);
    push(&s, 1);

    printf("Current Top = %d, Minimum = %d\n", top(&s), getMin(&s)); // Top: 1, Min: 1

    pop(&s);
    printf("Current Top = %d, Minimum = %d\n", top(&s), getMin(&s)); // Top: 8, Min: 2

    pop(&s);
    printf("Current Top = %d, Minimum = %d\n", top(&s), getMin(&s)); // Top: 2, Min: 2

    return 0;
}
