#include<stdio.h>
#define MAX 5

typedef struct Queue{
    int data[MAX];
    int front;
    int rear;
}Queue;

void init(Queue* q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q){
    return (q->front == -1 && q->rear == -1);
}

int isFull(Queue* q){
    return ((q->rear + 1) % MAX) == q->front; 
}

void enqueue(Queue* q, int value){
    if(isFull(q)){
        printf("Queue is Full\n");
        return;
    }

    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    } else{
        q->rear = (q->rear + 1) % MAX;
    }

    q->data[q->rear] = value;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }
    int value = q->data[q->front];

    //Last Element
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    } else{
        q->front = (q->front + 1) % MAX;
    }

    return value;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue Empty\n");
        return;
    }

    int i = q->front;

    while(1){
        printf("%d ", q->data[i]);
        if(i == q->rear){
            break;
        }
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    Queue q;
    init(&q);

    printf("Initial Queue:\n");
    display(&q);

    printf("\nEnqueue 10,20,30,40\n");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    printf("\nDequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    display(&q);

    printf("\nEnqueue 50\n");
    enqueue(&q, 50);
    display(&q);

    printf("\nEnqueue 60 (Wrap Around)\n");
    enqueue(&q, 60);
    display(&q);

    printf("\nTrying to enqueue 70\n");
    enqueue(&q, 70);

    printf("\nCurrent Queue:\n");
    display(&q);

    printf("\nRemoving all elements:\n");
    while(!isEmpty(&q))
    {
        printf("%d ", dequeue(&q));
    }

    printf("\n");

    display(&q);

    return 0;
}
