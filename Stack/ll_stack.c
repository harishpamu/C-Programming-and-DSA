/*
* Stack Implementation Using Linked List
*
* Stack follows LIFO (Last In First Out)
*
* Advantages over Array Stack:
* 1. Dynamic Size
* 2. No Stack Overflow due to fixed array size
* 3. Memory allocated as needed
*
* Operations:
* Push
* Pop
* Peek
* Display
* IsEmpty
*
* Time Complexity:
* Push : O(1)
* Pop : O(1)
* Peek : O(1)
* Display : O(n)
*
* Space Complexity:
* O(n)
*/
#include<stdio.h>
#include<stdlib.h>

/* Node of Linked List */
typedef struct Node{
    int data;
    struct Node* next;
}Node;

/* Stack Structure */
typedef struct Stack{
    Node* top; /* Points to top node */
    int count; /* Number of elements */
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

    /*
    * New node points to old top.
    */
    newNode->next = s->top;

    /*
    * Update top.
    */
    s->top = newNode;
    s->count++;
    printf("%d pushed into stack\n", value);
}

int pop(Stack* s){
    if(s->top == NULL){
        printf("Stack UnderFlow\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;

    /*
    * Move top to next node.
    */
    s->top = s->top->next;
    free(temp);
    s->count--;
    return value;
}

/*
* Peek Operation
*
* Returns top element
* without removing it.
*
* Time Complexity : O(1)
*/
int peek(Stack* s){
    if(s->top == NULL){
        printf("Stack is Empty\n");
        return -1;
    }

    return s->top->data;
}

void display(Stack *s){
    if (s->top == NULL){
        printf("Stack is Empty\n");
        return;
    }
    Node *current = s->top;
    printf("\n----- Stack -----\n");
    while (current){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

/*
* Returns current size.
*
* Time Complexity : O(1)
*/
int size(Stack *s){
    return s->count;
}

/*
* Free all nodes.
*
* Important to avoid memory leaks.
*
* Time Complexity : O(n)
* Space Complexity: O(1)
*/
void destroy(Stack *s){
    Node *current = s->top;

    while (current){
        Node *next = current->next;

        free(current);
        current = next;
    }
    s->top = NULL;
    s->count = 0;
}

int main(){
    Stack s;
    init(&s);   
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    display(&s);

    printf("Top Element = %d\n", peek(&s));

    printf("Popped Element = %d\n", pop(&s));

    printf("Stack After Pop: ");
    display(&s);

    printf("Current Size = %d\n", size(&s));

    destroy(&s);
    return 0;
}
