#include <stdio.h>
#include <stdlib.h>
#include"utils.h"

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Allocation Failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;   // Save next node
        curr->next = prev;   // Reverse link
        prev = curr;         // Move prev forward
        curr = next;         // Move curr forwar

    }

    return prev;
}

Node* findMiddle(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return 1;
        }
    }

    return 0;
}

Node* findLoopStart(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
    return NULL;
}

void removeLoop(Node* head){
    Node* start = findLoopStart(head);
    if(start == NULL){
        return;
    }
    Node* temp = start;
    while(temp->next != start){
        temp = temp->next;
    }

    temp->next = NULL;
}