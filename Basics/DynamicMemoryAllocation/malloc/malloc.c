#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*)malloc(5 * sizeof(int));
    if(ptr == NULL){
        printf("Allocation Failed\n");
        return 1;
    }

    printf("After malloc: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", ptr[i]); // Mostly Unexpected values - indeterminate (garbage) values.
    }
    printf("\n");

    printf("After Adding Value: ");
    for(int i = 0; i < 5; i++){
        ptr[i] = i + 1;
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", ptr[i]);
    }

    free(ptr);

    printf("\n");
    return 0;
}