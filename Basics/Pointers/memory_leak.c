#include <stdio.h>
#include <stdlib.h>

int main(){
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