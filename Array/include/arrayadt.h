#ifndef ARRAYADT_H
#define ARRAYADT_H
#include<stdio.h>
#define MAX_SIZE 10

typedef struct Array{
    int data[MAX_SIZE];
    int size;
}Array;

// Display - O(n)
// Append - O(1)
// Insert - O(n)
// Delete - O(n)
// Search - O(n)
// Get - O(1), Set - O(1)
// Min - O(n), Max - O(n)
// Reverse - O(n)
// Rotate Left - O(n)
// Rotate Right - O(n)
void display(Array arr);
void append(Array *arr, int value);
void insert(Array *arr, int index, int value);
int delete_value(Array *arr, int index);
int search(Array a, int key);
int get(Array a, int index);
void set(Array *a, int index, int value);
int min(Array a);
int max(Array a);
void reverse(Array *a);
void rotateLeft(Array *a);
void rotateRight(Array *a);

#endif