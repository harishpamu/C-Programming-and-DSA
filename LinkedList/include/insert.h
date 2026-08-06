#ifndef INSERT_H
#define INSERT_H
#include<stdio.h>
#include<stdlib.h>

#include"utils.h"

Node* insertAtBegin(Node* head, int value);
Node* insertAtEnd(Node* head, int value);
Node* insertAtPosition(Node* head, int value, int pos);
Node* insertAfter(Node* head, int key, int value);
Node* insertBefore(Node* head, int key, int value);

#endif