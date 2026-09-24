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
void freeList(Node* head);
int countNodes(struct Node *head);

// Linked List Operations
Node* search(Node* head, int key);
Node* reverse(Node* head);
Node* reverseRecursive(Node* head);
Node* rotateList(Node* head, int k);
Node* findMiddle(Node* head);

//loop
int detectLoop(Node* head);
// Find Starting Node of Loop
Node* findLoopStart(Node* head);
void removeLoop(Node* head);

Node* getNthNode(Node* head, int pos);
Node* getNthFromEnd(Node* head, int pos);
int lengthRecursive(Node* head);

Node* mergeSortedLists(Node* l1, Node* l2);
Node* removeDuplicates(Node* head);
int isPalindrome(Node* head);
Node* intersectionPoint(Node* head1, Node* head2);

#endif