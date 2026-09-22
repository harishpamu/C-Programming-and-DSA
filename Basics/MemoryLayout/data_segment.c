/*
 * Initialized global variables.
 */

#include <stdio.h>

int g_num = 100; // Lives in Data Srgment 

int main(){
    printf("%d\n", g_num);

    return 0;
}