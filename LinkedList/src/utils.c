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

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
int countNodes(struct Node* head){
    int count = 0;
    Node * temp = head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;   
}

/*
 * Free entire linked list.
 *
 * This function traverses the list
 * and releases memory occupied by
 * every node.
 *
 * After calling this function,
 * the list should not be accessed.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

void freeList(Node* head){
    Node* temp = NULL;

    while(head != NULL){
        temp = head;          /* Save current node */
        head = head->next;    /* Move to next node */
        free(temp);           /* Free current node */
    }
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

/*
 * Reverse linked list using recursion.
 *
 * Example:
 * 10 -> 20 -> 30 -> NULL
 *
 * Result:
 * 30 -> 20 -> 10 -> NULL
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(n)
 * (Recursive Call Stack)
 */

Node* reverseRecursive(Node* head){
    /* Empty list or single node */
    if(head == NULL || head->next == NULL){
        return head;
    }

    /* Reverse remaining list */
    Node* newHead = reverseRecursive(head->next);

    /*
     * Current:
     * head -> next -> ...
     *
     * Make:
     * next -> head
     */
    head->next->next = head;

    /* Break old link */
    head->next = NULL;

    return newHead;
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

/*
 * Rotate linked list by k positions.
 *
 * Example:
 * 10 -> 20 -> 30 -> 40 -> 50
 * k = 2
 * Result:
 * 40 -> 50 -> 10 -> 20 -> 30
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */
Node* rotateList(Node* head, int k){
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }

    int length = 1;
    Node* tail = head;

    /* Find length and last node */
    while(tail->next != NULL){
        tail = tail->next;
        length++;
    }

    /*
     * If k is larger than length
     */
    k = k % length;

    if(k == 0){
        return head;
    }

    /* Make circular list */
    tail->next = head;

    /*
     * Find new tail.
     *
     * Example:
     * n = 5
     * k = 2
     *
     * Move (5-2-1)=2 steps
     */
    int steps = length - k - 1;

    Node* newTail = head;

    while(steps--){
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    /* Break circular link */
    newTail->next = NULL;

    return newHead;
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

/*
 * Search for a key in the linked list.
 *
 * Returns:
 * Pointer to node if found
 * NULL otherwise
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

Node* search(Node* head, int key) {
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == key){
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

/*
 * Get Nth node from beginning.
 *
 * Position starts from 1.
 *
 * Example:
 * 10 -> 20 -> 30 -> 40
 *
 * pos = 1 => 10
 * pos = 3 => 30
 *
 * Returns:
 * Pointer to node if position valid
 * NULL otherwise
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */
Node* getNthNode(Node* head, int pos){
    if(pos <= 0){
        return NULL;
    }

    int count = 1;
    Node* temp = head;
    while(temp != NULL){
        if(count == pos){
            return temp;
        }

        count++;
        temp = temp->next;
    }

    return NULL;
}

/*
 * Get Nth node from end.
 *
 * Example:
 * 10 -> 20 -> 30 -> 40 -> 50
 *
 * pos = 1 => 50
 * pos = 2 => 40
 * pos = 3 => 30
 *
 * Uses two pointers:
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */
Node* getNthFromEnd(Node* head, int pos){
    if(head == NULL || pos <= 0){
        return NULL;
    }

    Node* first = head;
    Node* second = head;

    /*
     * Move first pointer
     * pos steps ahead.
     */
    for(int i = 0; i < pos; i++){
        if(first == NULL){
            return NULL;
        }

        first = first->next;
    }

    /*
     * Move both pointers
     * until first reaches end.
     */
    while(first != NULL){
        first = first->next;
        second = second->next;
    }

    return second;
}

/*
 * Count nodes using recursion.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(n)
 * (Recursive Call Stack)
 */
int lengthRecursive(Node* head){
    if(head == NULL){
        return 0;
    }

    return 1 + lengthRecursive(head->next);
}

/*
 * Merge two sorted linked lists.
 *
 * List1: 1 -> 3 -> 5
 * List2: 2 -> 4 -> 6
 *
 * Result:
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *
 * Time Complexity  : O(n + m)
 * Space Complexity : O(1)
 */
Node* mergeSortedLists(Node* l1, Node* l2){
    if(l1 == NULL){
        return l2;
    }

    if(l2 == NULL){
        return l1;
    }

    Node* head = NULL;
    Node* tail = NULL;

    /* Select first node */
    if(l1->data <= l2->data){
        head = tail = l1;
        l1 = l1->next;
    }else {
        head = tail = l2;
        l2 = l2->next;
    }

    /* Merge remaining nodes */
    while(l1 != NULL && l2 != NULL){
        if(l1->data <= l2->data){
            tail->next = l1;
            l1 = l1->next;
        }else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    /* Attach remaining nodes */
    if(l1 != NULL){
        tail->next = l1;
    }else {
        tail->next = l2;
    }

    return head;
}

/*
 * Remove duplicates from a sorted linked list.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

Node* removeDuplicates(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;

    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* duplicate = curr->next;

            curr->next = duplicate->next;

            free(duplicate);
        }else {
            curr = curr->next;
        }
    }

    return head;
}

/*
 * Check whether linked list is palindrome.
 *
 * Approch:
    Find middle.
    Reverse second half.
    Compare both halves.
    Restore list (optional).
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

int isPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return 1;
    }

    Node *slow = head;
    Node *fast = head;

    /* Find middle */
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half */
    Node *prev = NULL;
    Node *curr = slow;
    Node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    /* Compare both halves */
    Node *first = head;
    Node *second = prev;

    while(second != NULL){
        if(first->data != second->data){
            return 0;
        }

        first = first->next;
        second = second->next;
    }

    return 1;
}

/*
 * Find intersection point of two linked lists.
 *
 * Time Complexity  : O(n + m)
 * Space Complexity : O(1)
 */

Node* intersectionPoint(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }

    Node* p1 = head1;
    Node* p2 = head2;

    /*
     * When one pointer reaches end,
     * move it to the other list.
     */

    while(p1 != p2){
        if(p1 == NULL){
            p1 = head2;
        }else {
            p1 = p1->next;
        }

        if(p2 == NULL){
            p2 = head1;
        }else {
            p2 = p2->next;
        }
    }

    return p1;
}