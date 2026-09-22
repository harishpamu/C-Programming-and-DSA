#include<stdio.h>
#include<stdlib.h>

/* Structure*/
struct Student{
    int id;
    char name[20];
};

/* Function using pointer */
void update(int *num){
    *num = 100;
}

/* swap using pointers */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int add(int a, int b){
    return a + b;
}

void execute(int (*callback)(int,int))
{
    printf("%d\n", callback(10,20));
}

int main(){
    printf("\n========== 1. Basic Pointer ==========\n");
    int x = 10;
    int *ptr = &x;

    printf("x = %d\n", x);
    printf("&x = %p\n", (void *)&x);
    printf("ptr = %p\n", (void *)ptr);
    printf("*ptr = %d\n", *ptr);

    printf("\n========== 2. Modify Through Pointer ==========\n");
    *ptr = 20;
    printf("x = %d\n", x);

    printf("\n========== 3. Pointer Arithmetic ==========\n");
    int arr[] = {10, 20, 30, 40, 50};
    /*
    * Array Memory Layout
    *
    * Address     Value
    * -------     -----
    * 1000         10
    * 1004         20
    * 1008         30
    * 1012         40
    * 1016         50
    *
    * Array name stores address of first element.
    *
    * arr == &arr[0]
    */

    int *p = arr;
    /*
    * p points to first element.
    *
    *      p
    *      |
    *      v
    * +----+----+----+----+----+
    * | 10 | 20 | 30 | 40 | 50 |
    * +----+----+----+----+----+
    */
    printf("arr      = %p\n", (void *)arr);
    printf("&arr[0]  = %p\n", (void *)&arr[0]);

    printf("\nBefore Increment:\n");
    printf("*p = %d\n", *p);

    /*
    * Pointer Arithmetic
    *
    * Since p is int*
    *
    * p++
    *
    * moves by sizeof(int)
    *
    * Example:
    * 1000 -> 1004
    */
    p++;

    printf("\nAfter Increment:\n");
    printf("*p = %d\n", *p);

    /*
    * Array name is not modifiable.
    * arr++;   // ERROR
    * Reason:
    * Array name is a constant address.
    *
    * Pointer can move.
    * p++;     // OK
    */
    /*--------------------------------------------------*/

    printf("\n========== Array vs &Array ==========\n");
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
    printf("arr      = %p\n", (void *)arr);
    printf("&arr     = %p\n", (void *)&arr);

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
    /*--------------------------------------------------*/

    printf("\n========== 4. Array And Pointer ==========\n");
    /*
    * Array Traversal Using Pointer
    * arr[i]
    * is internally:
    * *(arr + i)
    */
    for(int i = 0; i < 5; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");

    printf("\n========== 5. Pointer To Pointer ==========\n");
    int **pptr = &ptr;
    printf("x = %d\n", x);
    printf("*ptr = %d\n", *ptr);
    printf("**pptr = %d\n", **pptr);

    printf("\n========== 6. Function Using Pointer ==========\n");
    update(&x);
    printf("Updated x = %d\n", x);

    printf("\n========== 7. Swap Using Pointer ==========\n");
    int a = 10;
    int b = 20;
    printf("Before Swap : a=%d b=%d\n", a, b);
    
    swap(&a, &b);
    printf("After Swap : a=%d b=%d\n", a, b);

    printf("\n========== Dynamic Memory ==========");
    printf("\n========== 8. malloc ==========\n");
    int *m = (int *)malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++){
        m[i] = i + 1;
    }
    for(int i = 0; i < 5; i++){
        printf("%d ", m[i]);
    }
    printf("\n");

    printf("\n========== 9. calloc ==========\n");
    int *c = (int *)calloc(5, sizeof(int));
    for(int i = 0; i < 5; i++){
        printf("%d ", c[i]);
    }
    printf("\n");

    printf("\n========== 10. realloc ==========\n");
    m = (int *)realloc(m, 10*sizeof(int));
    for(int i = 5; i < 10; i++){
        m[i] = i + 1;
    }
    for(int i = 0; i < 10; i++){
        printf("%d ", m[i]);
    }
    printf("\n");

    printf("\n========== 11. Void Pointer ==========\n");
    void *vp = &x;
    printf("%d\n", *(int *)vp);

    printf("\n========== 12. Structure Pointer ==========\n");
    struct Student s = {
        .id = 101,
        .name = "Harish"
    };
    struct Student *sptr = &s;
    printf("ID   : %d\n", sptr->id);
    printf("Name : %s\n", sptr->name);

    printf("\n========== 13. Pointer To Array ==========\n");
    int nums[5] = {1,2,3,4,5};
    int (*arrPtr)[5] = &nums;
    printf("(*arrPtr)[2] = %d\n", (*arrPtr)[2]);

    printf("\n========== 14. Array Of Pointers ==========\n");
    char *name[] = {
        "Embedded",
        "Linux",
        "Driver"
    };

    for(int i = 0; i < 3; i++){
        printf("%s\n", name[i]);
    }

   /*=========================================================
    * Pointer Const Combinations
    *=========================================================
    *
    * 1. int *ptr
    *
    * Data    -> Mutable
    * Address -> Mutable
    *
    * Allowed:
    *      *ptr = 100;
    *      ptr = &x;
    *
    *---------------------------------------------------------
    *
    * 2. int *const ptr
    *
    * Constant Pointer
    *
    * Data    -> Mutable
    * Address -> Immutable
    *
    * Allowed:
    *      *ptr = 100;
    *
    * Not Allowed:
    *      ptr = &x;
    *
    *---------------------------------------------------------
    *
    * 3. const int *ptr
    *
    * Pointer To Constant
    *
    * Data    -> Immutable
    * Address -> Mutable
    *
    * Allowed:
    *      ptr = &x;
    *
    * Not Allowed:
    *      *ptr = 100;
    *
    *---------------------------------------------------------
    *
    * 4. const int *const ptr
    *
    * Constant Pointer To Constant
    *
    * Data    -> Immutable
    * Address -> Immutable
    *
    * Allowed:
    *      Read only
    *
    * Not Allowed:
    *      *ptr = 100;
    *      ptr = &x;
    *
    *=========================================================
    */
    printf("\n========== 15. Constant Pointer ==========\n");
    int n1 = 10;
    int n2 = 20;
    printf("n1 = %d, n2 = %d\n", n1, n2);
    /*
    *
    * int *const cp = &n1;
    *
    * Pointer is constant.
    * Data is NOT constant.
    *
    * Allowed:
    *   *cp = 50;      // Change value
    *
    * Not Allowed:
    *   cp = &n2;      // ERROR
    *
    * Error:
    *   assignment of read-only variable 'cp'
    */
    int *const cp = &n1;
    *cp = 50;      /* OK */
    printf("After *cp = 50:\n");
    printf("n1 = %d, n2 = %d\n", n1, n2);

    /* ERROR: Constant Pointer */
    /* cp = &n2; */

    printf("\n========== 16. Pointer To Constant ==========\n");
    /*
    * const int *pc = &n1;
    *
    * Data is constant.
    * Pointer is NOT constant.
    *
    * Allowed:
    *   pc = &n2;      // Change address
    *
    * Not Allowed:
    *   *pc = 50;      // ERROR
    *
    * Error:
    *   assignment of read-only location '*pc'
    */
    const int *pc = &n1;
    printf("pc -> n1 = %d\n", *pc);
    pc = &n2;      /* OK */
    printf("After pc = &n2:\n");
    printf("pc -> n2 = %d\n", *pc);

    printf("Current Values:\n");
    printf("n1 = %d, n2 = %d\n", n1, n2);

    /* ERROR: Read-only data */
    /* *pc = 50; */

    printf("\n========== 17. Constant Pointer To Constant ==========\n");
    /*
    * const int *const cpc = &n1;
    *
    * Data is constant.
    * Pointer is also constant*
    *
    * Allowed:
    *   printf("%d", *cpc);
    *
    * Not Allowed:
    *   *cpc = 50;     // ERROR
    *   cpc = &n2;     // ERROR
    *
    * Errors:
    *   assignment of read-only location '*cpc'
    *   assignment of read-only variable 'cpc'
    */
    const int *const cpc = &n1;
    printf("cpc -> %d\n", *cpc);

    printf("After Operations:\n");
    printf("n1 = %d, n2 = %d\n", n1, n2);

    /* ERROR: Cannot modify data */
    /* *cpc = 50; */

    /* ERROR: Cannot modify address */
    /* cpc = &n2; */

    printf("\n========== 18. NULL Pointer ==========\n");
    int *nullPtr = NULL;
    if(nullPtr == NULL){
        printf("NULL pointer\n");
    }

    printf("\n========== 19. Double Pointer With malloc ==========\n");
    int *dp = (int *)malloc(sizeof(int));
    *dp = 999;
    int **dpp = &dp;
    printf("%d\n", **dpp);

    printf("\n========== 20. Dangling Pointer ==========\n");
    free(dp);
    dp = NULL;
    printf("Pointer set to NULL after free\n");

    // Situational Example
    int *dangling = malloc(sizeof(int));

    *dangling = 50;

    free(dangling);

    /*
    * Dangerous:
    * Memory already released.
    */

    /* printf("%d\n", *dangling); */

    /*
    * Correct
    */
    dangling = NULL;


    // FREE MEMORY
    free(m);
    free(c);

    printf("\n========== 21. Function Pointer & callback ==========\n");
    int (*fp)(int, int) = add;
    printf("Result = %d\n", fp(10, 20));

    execute(add);

    printf("\n========== 22. Structure Pointer Arithmetic ==========\n");
    struct Student students[2] =
    {
        {101, "Harish"},
        {102, "Linux"}
    };
    struct Student *sp = students;
    printf("%d %s\n", sp->id, sp->name);
    sp++;
    printf("%d %s\n", sp->id, sp->name);

    printf("\n========== 23. Pointer Sizes ==========\n");
    printf("sizeof(int*)    = %zu\n", sizeof(int *));
    printf("sizeof(char*)   = %zu\n", sizeof(char *));
    printf("sizeof(float*)  = %zu\n", sizeof(float *));
    printf("sizeof(void*)   = %zu\n", sizeof(void *));

    printf("\n========== 24. Wild Pointer ==========\n");
    /*
    * Pointer declared but not initialized.
    *
    * Dangerous:
    * Contains garbage address.
    */
    //int *wildPtr;

    /* Never dereference - Dereferencing causes undefined behaviour. */
    // printf("%d\n", *wildPtr);

    printf("\n========== 27. Memory Layout ==========\n");
    int local = 10;
    static int st = 20;

    int *heapPtr = malloc(sizeof(int));

    printf("Stack  = %p\n", (void*)&local);
    printf("Static = %p\n", (void*)&st);
    printf("Heap   = %p\n", (void*)heapPtr);

    free(heapPtr);


    printf("\n========== 25. Memory Leak ==========\n");
    /*
    * Memory allocated but never freed.
    * Causes memory leak.
    * Bad Practice:
    */
    int *leak = (int *)malloc(sizeof(int));
    *leak = 100;
    printf("Value = %d\n", *leak);

    /*
    * Missing:
    *
    * free(leak);
    *
    * Memory remains allocated
    * until program exits.
    */

    /* Fix */
    free(leak);
    
    return 0;
}