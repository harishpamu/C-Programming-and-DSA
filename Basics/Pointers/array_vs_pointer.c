#include <stdio.h>

int main(){
    int arr[5] = {10,20,30,40,50};

    /*
    * arr
    * ----
    * Type:
    *      int *
    * Meaning:
    *      Address of first element
    *
    *
    * &arr
    * ----
    * Type:
    *      int (*)[5]
    * Meaning:
    *      Pointer to entire array
    *
    *
    * Although arr and &arr print the
    * same address value, their types
    * are different.
    */
    printf("arr      = %p\n",(void *)arr);
    printf("&arr     = %p\n",(void *)&arr);

    /*
    * arr + 1
    * Moves by sizeof(int)
    *
    * Example:
    * 1000 -> 1004
    *
    * &arr + 1
    * Moves by sizeof(entire array)
    *
    * Array Size:
    * 5 * sizeof(int)
    * = 20 bytes
    *
    * Example:
    * 1000 -> 1020
    */
    printf("arr + 1  = %p\n", (void *)(arr + 1));
    printf("&arr + 1 = %p\n", (void *)(&arr + 1));

    /*
    * Array Traversal Using array notation
    * *(arr + i)
    */
   printf("Loop *(arr + i): ");
    for(int i = 0; i < 5; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");

    /*
    * Array Traversal Using pointer
    * 
    */
    int *ptr = arr;
    printf("Loop *ptr++: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
    return 0;
}