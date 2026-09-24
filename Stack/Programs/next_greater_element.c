/*
 * For every element in an array, find the first greater
 * element present on its right side.
 *
 * If no greater element exists, print -1.
 *
 * Example:
 * Input:
 * ------
 * 4 5 2 25
 *
 * Output:
 * -------
 * 4  -> 5
 * 5  -> 25
 * 2  -> 25
 * 25 -> -1
 *
 * Approach:
 * ---------
 * Use a Stack to keep track of elements whose
 * Next Greater Element has not yet been found.
 *
 * Time Complexity:
 * ----------------
 * O(n)
 *
 * Each element is:
 * 1. Pushed exactly once.
 * 2. Popped exactly once.
 *
 * Therefore total operations = 2n.
 *
 * Space Complexity:
 * -----------------
 * O(n)
 *
 * Stack may contain at most n elements.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct Stack{
    int data[MAX];
    int top;
} Stack;

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    return (s->top == -1);
}

bool isFull(Stack *s) {
    return s->top >= MAX - 1;
}

void push(Stack *s, int value){
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s){
    if (isEmpty(s)) {
        return -1;
    }
    return s->data[s->top--];
}

int peek(Stack *s){
    return s->data[s->top];
}

/*
 * Find Next Greater Element.
 *
 * Time  : O(n)
 * Space : O(n)
 */
void nextGreaterElement(int arr[], int n) {
    Stack s;
    init(&s);

    // Array to store the final NGE answers mapped to their original positions
    int result[MAX];

    // Traverse the array from left to right
    for (int i = 0; i < n; i++) {
        /*
         * While the stack is not empty AND the current element is strictly
         * greater than the element represented by the index at the top of the stack.
         */
        while (!isEmpty(&s) && arr[peek(&s)] < arr[i]) {
            int targetIndex = pop(&s);
            result[targetIndex] = arr[i]; // Save the NGE for this specific position
        }

        // Push the CURRENT element's index onto the stack
        push(&s, i);
    }

    // Any indices remaining in the stack have no greater element to their right
    while (!isEmpty(&s)) {
        int targetIndex = pop(&s);
        result[targetIndex] = -1;
    }

    // Print the results in perfect sequential order matching the input array
    for (int i = 0; i < n; i++) {
        printf("%-3d -> %d\n", arr[i], result[i]);
    }
}

int main(){
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array:\n");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nNext Greater Elements:\n");

    nextGreaterElement(arr, n);

    return 0;
}