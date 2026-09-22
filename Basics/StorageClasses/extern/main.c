/*
 * Declaration
 */

#include <stdio.h>

extern int g_count; // access global variables defined elsewhere(globals.c here).
extern void display(); // Extern Function

int main()
{
    printf("g_count = %d\n", g_count);
    display();

    return 0;
}

// Run this -> gcc globals.c main.c -o main