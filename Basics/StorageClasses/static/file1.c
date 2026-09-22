#include <stdio.h>

static int g_count = 100; 
/*
   - has internal linkage.
   - Visible only inside file1.c.
*/

void display()
{
    printf("g_count = %d\n", g_count);
}