#include"utils.h"
#include"insert.h"
#include"delete.h"


int main()
{
    Node* head = NULL;

    printf("Insert At Beginning:\n");
    head = insertAtBegin(head, 30);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 10);
    display(head);

    printf("\nInsert At End:\n");
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    display(head);

    printf("\nInsert At Position (3):\n");
    head = insertAtPosition(head, 25, 3);
    display(head);

    printf("\nInsert After 30:\n");
    head = insertAfter(head, 30, 35);
    display(head);

    printf("\nInsert Before 40:\n");
    head = insertBefore(head, 40, 38);
    display(head);


    head = deleteAtBegin(head);
    display(head);

    head = deleteAtEnd(head);
    display(head);

    head = deleteAtPosition(head, 3);
    display(head);

    head = deleteByValue(head, 30);
    display(head);

    head = reverse(head);
    display(head);


    Node* mid = findMiddle(head);
    if(mid != NULL)
    {
        printf("Middle Node = %d\n", mid->data);
    }


    // Node* temp = head;
    // while(temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = head->next; // create loop

    if(detectLoop(head)){
        printf("Loop Detected\n");
        
        Node* start = findLoopStart(head);
        if(start != NULL)
        {
            printf("Loop starts at %d\n", start->data);
        }
        
        removeLoop(head);
        printf("Loop removed\n");
    } else{
        printf("No Loop Found\n");
    }

    display(head);

    return 0;
}

