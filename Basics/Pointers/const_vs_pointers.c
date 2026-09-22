#include <stdio.h>

int main(){
    printf("========== Constant Pointer ==========\n");
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

    printf("\n========== Pointer To Constant ==========\n");
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

    printf("\n========== Constant Pointer To Constant ==========\n");
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
}