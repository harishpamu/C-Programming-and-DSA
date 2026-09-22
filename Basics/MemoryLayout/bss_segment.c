/*
 * Uninitialized global variables - lives in BSS Segment.
 */

#include <stdio.h>

int g_num;

static int count;

int main(){
    printf("%d %d\n", g_num, count);

    return 0;
}