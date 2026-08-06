#ifndef UTILS_H
#define UTILS_H
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createNode(int value);
void display(Node* head);

// Linked List Operations
Node* reverse(Node* head);
Node* findMiddle(Node* head);

//loop
int detectLoop(Node* head);
// Find Starting Node of Loop
Node* findLoopStart(Node* head);
void removeLoop(Node* head);
#endif