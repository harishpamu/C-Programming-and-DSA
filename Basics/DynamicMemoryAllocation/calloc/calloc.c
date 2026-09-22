#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*)calloc(5, sizeof(int));
    if(ptr == NULL){
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    printf("After calloc: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", ptr[i]); // Zeros Initially
    }
    printf("\n");

    printf("After Adding Value: ");
    for(int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", ptr[i]);
    }
    printf("\n");
    free(ptr);

    return 0;
}