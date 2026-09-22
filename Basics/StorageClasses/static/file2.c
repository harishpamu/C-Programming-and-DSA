#include <stdio.h>

// Compl
extern int g_count; // undefined reference

int main()
{
    printf("%d\n", g_count); 

    return 0;
}