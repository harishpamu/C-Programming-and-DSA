#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
    int count;
}Queue;

void init(Queue* q){
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

int isEmpty(Queue* q){
    return (q->front == NULL);
}

void enqueue(Queue* q, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Allocation Failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(q->rear == NULL){
        q->front = newNode;
        q->rear = newNode;
    } else{
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->count++;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);
    q->count--;

    return value;
}

int size(Queue* q){
    return q->count;
}

int peek(Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }

    return q->front->data;
}

void display(Queue* q){
    Node* temp = q->front;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    Queue q;
    init(&q);

    printf("Is Empty: %s\n",isEmpty(&q) ? "Yes" : "No");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue: ");
    display(&q);

    printf("Size: %d\n", size(&q));
    printf("Front Element: %d\n", peek(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    printf("Queue After Dequeue: ");
    display(&q);

    printf("Front Element: %d\n", peek(&q));

    printf("Size: %d\n", size(&q));

    printf("Removing All Elements:\n");

    while(!isEmpty(&q)){
        printf("%d ", dequeue(&q));
    }

    printf("\n");

    printf("Is Empty: %s\n",isEmpty(&q) ? "Yes" : "No");
    display(&q);

    return 0;
}
