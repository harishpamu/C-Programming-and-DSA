#include"insert.h"
#include"utils.h"

Node* insertAtBegin(Node* head, int value){
    Node* newNode = createNode(value);
    if(newNode == NULL){
        return head;
    }

    newNode->next = head;
    head = newNode;

    return head;
}

Node* insertAtEnd(Node* head, int value){
    Node* newNode = createNode(value);
    if(newNode == NULL){
        return head;
    }
    
    if(head == NULL){
        return newNode;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int value, int pos){
    /*
    If pos == 1, insert at beginning.
    Traverse to (pos - 1) node.
    Create a new node.
    Adjust links.
    */
    if(pos < 1){
        return head;
    }
    if(pos == 1){
        return insertAtBegin(head, value);
    }
    Node* newNode = createNode(value);
    if(newNode == NULL){
        return head;
    }

    Node* temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertAfter(Node* head, int key, int value){
    /*
    Traverse the list.
    Find the node containing key.
    Create a new node.
    Insert the new node after the key node.
    Return head.
    */
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            Node* newNode = createNode(value);
            if(newNode == NULL){
                return head;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            return head;
        }
        temp = temp->next;
    }
    printf("Key Not Found\n");
    return head;
}

Node* insertBefore(Node* head, int key, int value){
    Node* newNode = createNode(value);
    if(newNode == NULL){
        return head;
    }

    // Insert before first node
    if(head != NULL && head->data == key){
        newNode->next = head;
        return newNode;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL && curr->data != key){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        printf("Key Not Found\n");
        free(newNode);
        return head;
    }

    prev->next = newNode;
    newNode->next = curr;

    return head;
}