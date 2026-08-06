#ifndef DELETE_H
#define DELETE_H

#include"utils.h"

Node* deleteAtBegin(Node* head);
Node* deleteAtEnd(Node* head);
Node* deleteAtPosition(Node* head, int pos);
Node* deleteByValue(Node* head, int value);

#endif