#include<stdio.h>
#include<string.h>

/* Heap Memory Pool */
#define HEAP_SIZE 100

char heap[HEAP_SIZE];
int offset = 0; // This tracks the next free allocation

// malloc
void *my_malloc(int size){
    if(offset + size > HEAP_SIZE){
        return NULL; //No space left
    }

    /* Store current free location */
    void *ptr = &heap[offset];

    /* Move offset to next free location */
    offset += size;

    return ptr;
}

/* Allocates memory and initializes it to zero. calloc(n, size)*/
void *my_calloc(int n, int size){
    int total_size = n * size;

    void *ptr = my_malloc(total_size);
    if(ptr != NULL){
        /* Initialize allocated memory with zero */
        memset(ptr, 0, total_size);
    }

    return ptr;
}

/* Allocates a new block and copies old data. - realloc(old_ptr, new_size) */
void *my_realloc(void *old_ptr, int old_size, int new_size){
    void *new_ptr = my_malloc(new_size);
    if(new_ptr == NULL){
        return NULL;
    }

    /* Copy old data into new allocation */
    memcpy(new_ptr, old_ptr, old_size < new_size? old_size : new_size);

    return new_ptr;
}

/*
* Dummy free implementation.
* Real free():
* - Releases memory
* - Updates allocator metadata
* - Allows memory reuse
*/
void my_free(void *ptr){
    (void)ptr;
    printf("Memory Freed\n");
}

int main(){
    /* malloc */
    int *p = (int *)my_malloc(sizeof(int));
    *p = 100;
    printf("malloc = %d\n", *p);
    
    /* calloc */
    int *arr = (int *)my_calloc(5, sizeof(int));
    printf("calloc = %d\n", arr[0]);

    /* realloc */
    int *new_p = (int *)my_realloc(p, sizeof(int), 2 * sizeof(int));
    printf("realloc = %d\n", *new_p);

    /* free */
    my_free(new_p);
    return 0;
}