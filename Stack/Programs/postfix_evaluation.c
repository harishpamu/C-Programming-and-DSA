/*
   Evaluate a Postfix Expression.
 *
 * Postfix:
 * Operator comes after operands.
 *
 * Example:
 * --------
 * 23*54*+9-
 *
 * Evaluation:
 * 2 * 3 = 6
 * 5 * 4 = 20
 * 6 + 20 = 26
 * 26 - 9 = 17
 *
 * Result = 17
 *
 * Algorithm:
 * ----------
 * 1. Traverse expression left to right.
 * 2. If operand:
 *      Push onto stack.
 * 3. If operator:
 *      Pop two operands.
 *      Perform operation.
 *      Push result back.
 * 4. Final stack element is answer.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(n)
 */

#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct Stack{
    int data[MAX];
    int top;
} Stack;

void init(Stack *s){
    s->top = -1;
}

void push(Stack *s, int value){
    if (s->top < MAX - 1) {
        s->data[++s->top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(Stack *s){
    if (s->top >= 0) {
        return s->data[s->top--];
    }
    printf("Stack Underflow (Invalid Postfix Expression)\n");
    return 0; // Or exit error
}

int evaluatePostfix(char exp[]){
    Stack s;
    init(&s);

    for (int i = 0; exp[i] != '\0'; i++){
        char ch = exp[i];

        if (isdigit(ch)){
            push(&s, ch - '0');
        }else {
            int b = pop(&s);
            int a = pop(&s);

            switch (ch){
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
            }
        }
    }

    return pop(&s);
}

int main(){
    char exp[] = "23*54*+9-";

    printf("Postfix Expression : %s\n", exp);
    printf("Result             : %d\n", evaluatePostfix(exp));

    return 0;
}