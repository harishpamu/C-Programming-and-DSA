#include <stdio.h>

#include "utils.h"
#include "insert.h"
#include "delete.h"

int main(){
    Node *head = NULL;
    printf("1. Insert At Beginning\n");
    head = insertAtBegin(head, 30);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 10);
    display(head);

    printf("\n2. Insert At End\n");
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    display(head);

    printf("\n3. Insert At Position (pos = 3, value = 25)\n");
    head = insertAtPosition(head, 25, 3);
    display(head);

    printf("\n4. Insert After Key 30\n");
    head = insertAfter(head, 30, 35);
    display(head);

    printf("\n5. Insert Before Key 40\n");
    head = insertBefore(head, 40, 38);
    display(head);
    printf("\n-------------------------------------\n");
    printf("Current List\n");
    display(head);
    
    printf("\n6. Count Nodes\n");
    printf("Total Nodes = %d\n", countNodes(head));
    printf("Recursive Length = %d\n",lengthRecursive(head));

    printf("\n7. Search Node\n");
    Node *result = search(head, 35);
    if(result != NULL){
        printf("Found Node = %d\n", result->data);
    }else {
        printf("Key Not Found\n");
    }

    printf("\n8. Get Nth Node From Beginning\n");
    Node *nth = getNthNode(head, 3);
    if(nth){
        printf("3rd Node = %d\n", nth->data);
    }

    printf("\n9. Get Nth Node From End\n");
    nth = getNthFromEnd(head, 2);
    if(nth){
        printf("2nd Node From End = %d\n", nth->data);
    }

    printf("\n10. Find Middle Node\n");
    Node *mid = findMiddle(head);
    if(mid){
        printf("Middle Node = %d\n", mid->data);
    }
    
    printf("\n11. Reverse (Iterative)\n");
    head = reverse(head);
    display(head);
    
    printf("\n12. Reverse (Recursive)\n");
    head = reverseRecursive(head);
    display(head);
    
    printf("\n13. Rotate List By 2 Positions\n");
    head = rotateList(head, 2);
    display(head);

    printf("\n14. Delete At Beginning\n");
    head = deleteAtBegin(head);
    display(head);

    printf("\n15. Delete At End\n");
    head = deleteAtEnd(head);
    display(head);

    printf("\n16. Delete At Position (3)\n");
    head = deleteAtPosition(head, 3);
    display(head);

    printf("\n17. Delete By Value (35)\n");
    head = deleteByValue(head, 35);
    display(head);
    
    printf("\n18. Merge Sorted Lists\n");
    Node *l1 = NULL;
    Node *l2 = NULL;
    l1 = insertAtEnd(l1, 1);
    l1 = insertAtEnd(l1, 3);
    l1 = insertAtEnd(l1, 5);

    l2 = insertAtEnd(l2, 2);
    l2 = insertAtEnd(l2, 4);
    l2 = insertAtEnd(l2, 6);

    printf("List 1: ");
    display(l1);

    printf("List 2: ");
    display(l2);

    Node *merged = mergeSortedLists(l1, l2);

    printf("Merged: ");
    display(merged);
    
    printf("\n19. Remove Duplicates\n");
    Node *dup = NULL;
    dup = insertAtEnd(dup, 1);
    dup = insertAtEnd(dup, 1);
    dup = insertAtEnd(dup, 2);
    dup = insertAtEnd(dup, 2);
    dup = insertAtEnd(dup, 3);
    dup = insertAtEnd(dup, 3);

    printf("Before : ");
    display(dup);

    dup = removeDuplicates(dup);
    printf("After  : ");
    display(dup);
    
    printf("\n20. Palindrome Check\n");
    Node *pal = NULL;
    pal = insertAtEnd(pal, 1);
    pal = insertAtEnd(pal, 2);
    pal = insertAtEnd(pal, 3);
    pal = insertAtEnd(pal, 2);
    pal = insertAtEnd(pal, 1);
    display(pal);

    if(isPalindrome(pal)){
        printf("Palindrome List\n");
    }else {
        printf("Not a Palindrome\n");
    }
    
    printf("\n21. Loop Detection\n");
    Node *loopList = NULL;
    loopList = insertAtEnd(loopList, 10);
    loopList = insertAtEnd(loopList, 20);
    loopList = insertAtEnd(loopList, 30);
    loopList = insertAtEnd(loopList, 40);

    Node *temp = loopList;
    while(temp->next != NULL){
        temp = temp->next;
    }

    /* Create Loop */
    temp->next = loopList->next;
    if(detectLoop(loopList)){
        printf("Loop Detected\n");
        Node *start = findLoopStart(loopList);

        if(start) {
            printf("Loop Starts At = %d\n", start->data);
        }
        removeLoop(loopList);
        printf("Loop Removed Successfully\n");

        printf("List After Loop Removal: ");
        display(loopList);
    }else {
        printf("No Loop Found\n");
    }

    printf("\n22. Intersection Point\n");
    Node *common = createNode(30);
    common->next = createNode(40);
    common->next->next = createNode(50);

    Node *head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = common;

    Node *head2 = createNode(15);
    head2->next = createNode(25);
    head2->next->next = common;
    display(common);
    display(head1);
    display(head2);
    
    Node *intersection = intersectionPoint(head1, head2);
    if(intersection != NULL){
        printf("Intersection Node = %d\n", intersection->data);
    }else {
        printf("No Intersection Found\n");
    }


    freeList(head);
    head = NULL;

    freeList(merged);
    merged = NULL;

    freeList(dup);
    dup = NULL;

    freeList(pal);
    pal = NULL;

    freeList(loopList);
    loopList = NULL;

    /* Free common intersection list once */
    freeList(head1);
    head1 = NULL;
    /* head2 shares nodes with head1 */
    head2 = NULL;

    return 0;
}