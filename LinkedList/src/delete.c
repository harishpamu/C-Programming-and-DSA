#include"delete.h"

/*
* Delete first node.
*
* Time Complexity : O(1)
* Space Complexity : O(1)
*/
Node* deleteAtBegin(Node* head){
    if(head == NULL){
        printf("List is Empty\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

/*
* Delete last node.
*
* Time Complexity : O(n)
* Space Complexity : O(1)
*/
Node* deleteAtEnd(Node* head){
    if(head == NULL){
        printf("List is Empty\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

/*
* Delete node at a given position.
*
* Position starts from 1.
*
* Time Complexity : O(n)
* Space Complexity : O(1)
*/
Node* deleteAtPosition(Node* head, int pos){
    if(head == NULL || pos < 1){
        return head;
    }
    if(pos == 1){
        return deleteAtBegin(head);
    }

    Node* temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        printf("Invalid Position\n");
        return head;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    free(nodeToDelete);
    return head;
}

/*
* Delete first occurrence
* of a given value.
*
* Time Complexity : O(n)
* Space Complexity : O(1)
*/
Node* deleteByValue(Node* head, int value){
    if(head == NULL){
        printf("List is Empty\n");
        return NULL;
    }    

    if(head->data == value){
        Node* temp = head;
        head = head->next;

        free(temp);
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL && curr->data != value){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        printf("Value not found\n");
        return head;
    }
    prev->next = curr->next;
    free(curr);

    return head;
}