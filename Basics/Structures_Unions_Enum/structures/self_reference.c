#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};

int main()
{
    struct Node n1;

    n1.data = 10;
    n1.next = NULL;

    return 0;
}   