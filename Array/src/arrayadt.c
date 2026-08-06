#include"arrayadt.h"
#include<stdio.h>

/*
display - O(n)
*/
void display(Array arr){
    printf("Elements: ");
    for(int i = 0; i < arr.size; i++){
        printf("%d ",arr.data[i]);
    }
    printf("\n");
}
/*
Append - 0(1)
*/
void append(Array *arr, int value){
    if(arr->size < MAX_SIZE){
        arr->data[arr->size++] = value;
    } else{
        printf("Array is full!\n");
    }
}

/*
Insert - O(n)
*/
void insert(Array *arr, int index, int value){
    if(index < 0 || index > arr->size || arr->size == MAX_SIZE){
        return;
    }

    for(int i = arr->size; i > index; i--){
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->size++;
}

/*
Delete - O(n)
*/
int delete_value(Array *arr, int index){
    if(index < 0 || index >= arr->size){
        return -1;
    }

    int value = arr->data[index];
    for(int i = index; i < arr->size; i++){
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;

    return value;
}

int search(Array a, int key){
    for(int i = 0; i < a.size; i++){
        if(a.data[i] == key){
            return 1;
        }
    }
    return -1;
}

int get(Array a, int index){
    if(index >= 0 && index < a.size){
        return a.data[index];
    }
    return -1;
}

void set(Array *a, int index, int value){
    if(index >= 0 && index < a->size){
        a->data[index] = value;
    }
}

int min(Array a){
    int m = a.data[0];
    for(int i = 0; i < a.size; i++){
        if(a.data[i] < m){
            m = a.data[i];
        }
    }
    return m;
}

int max(Array a){
    int m = a.data[0];
    for(int i = 0; i < a.size; i++){
        if(a.data[i] > m){
            m = a.data[i]; 
        }
    }
    return m;
}

void reverse(Array *a){
    int i = 0;
    int j = a->size - 1;
    while(i < j){
        int temp = a->data[i];
        a->data[i] = a->data[j];
        a->data[j] = temp;

        i++;
        j--;
    }
}

void rotateLeft(Array *a){
    int first = a->data[0];
    for(int i = 0; i < a->size; i++){
        a->data[i] = a->data[i + 1]; 
    }
    a->data[a->size - 1] = first;
}


void rotateRight(Array *a){
    int last = a->data[a->size - 1];

    for(int i = a->size - 1; i > 0; i--)
        a->data[i] = a->data[i - 1];

    a->data[0] = last;
}
