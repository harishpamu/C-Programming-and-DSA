/*
* Stack Implementation Using Array: 
* Stack follows LIFO (Last In First Out)
*
* Operations:
* 1. Push -> Insert element
* 2. Pop -> Remove top element
* 3. Peek -> View top element
* 4. isEmpty
* 5. isFull
* 6. Display
*
* Time Complexity:
* Push : O(1)
* Pop : O(1)
* Peek : O(1)
* isEmpty : O(1)
* isFull : O(1)
* Display : O(n)
*
* Space Complexity:
* O(n) where n = MAX stack size
*/
#include<stdio.h>

#define MAX 10
typedef struct Stack{
    int data[MAX];
    int top;
}Stack;

/*
* Initialize Stack
*
* Empty stack is represented using top = -1
*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/
void init(Stack* s){
    s->top = -1;
}

/*
* Check whether stack is empty
*
* Returns:
* 1 -> Empty
* 0 -> Not Empty
*
* Time Complexity : O(1)
*/
int isEmpty(Stack* s){
    return s->top == -1;
}

/*
* Check whether stack is full
*
* Returns:
* 1 -> Full
* 0 -> Not Full
*
* Time Complexity : O(1)
*/
int isFull(Stack* s){
    return s->top >= MAX - 1;
}

/*
* Add element at top of stack.
*/
void push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack is Full\n");
        return;
    }

    /*
    * Increment top first
    * Then store value.
    *
    * Example:
    * Current top = 1
    * ++top => 2
    * data[2] = value
    */
    s->data[++(s->top)] = value;
}

/*
* Removes top element.
*/
int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }

    /*
    * Return current top element.
    * Then decrement top.
    *
    * Example:
    * top = 2
    * return data[2]
    * top becomes 1
    */
    return s->data[s->top--];
}


/*
* Returns top element without removing it.
*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/
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

int main(){
    Stack s;
    
    /* Initialize stack */
    init(&s);

    printf("Pushing Elements: ");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("\nStack Elements:\n");
    display(&s);

    printf("\nPeek Element = %d\n", peek(&s));

    printf("Popped Element = %d\n", pop(&s));

    printf("Stack After Pop:\n");
    display(&s);

    return 0;
}