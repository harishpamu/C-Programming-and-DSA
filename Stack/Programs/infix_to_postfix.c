/*
 * Convert Infix Expression to Postfix.
 *
 * Example:
 * A+B*C
 *
 * Infix:
 * -------
 * A + B * C
 *
 * Postfix:
 * --------
 * ABC*+
 *
 * Why?
 * ----
 * Postfix expressions do not need brackets
 * and are easy to evaluate using stacks.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(n)
 */
#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, char ch) { s->data[++s->top] = ch; }
char pop(Stack *s) { return s->data[s->top--]; }
char peek(Stack *s) { return s->data[s->top]; }

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3; // Right-associative
    }
    return 0;
}

void infixToPostfix(char infix[]) {
    Stack s;
    init(&s);

    char postfix[MAX];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // 1. If operand, add directly to output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } 
        // 2. If opening bracket, push to stack
        else if (ch == '(') {
            push(&s, ch);
        } 
        // 3. If closing bracket, pop until opening bracket is found
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove the '(' from stack
        } 
        // 4. Operator encountered
        else {
            // Check precedence and associativity
            while (!isEmpty(&s) && (
                   (ch != '^' && precedence(peek(&s)) >= precedence(ch)) || 
                   (ch == '^' && precedence(peek(&s)) > precedence(ch))
                  )) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop all remaining operators
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';

    printf("Infix   : %s\n", infix);
    printf("Postfix : %s\n", postfix);
    printf("\n");
}

int main() {
    char infix1[] = "A+B*C";
    char infix2[] = "(A+B)*C";
    char infix3[] = "A^B^C";

    infixToPostfix(infix1); // Output: ABC*+
    infixToPostfix(infix2); // Output: AB+C*
    infixToPostfix(infix3); // Output: ABC^^

    return 0;
}
