/*
 * auto.c
 *
 * auto variables are created when function starts
 * and destroyed when function ends.
 * 
 * Rarely used explicitly because local variables are auto by default.
 */
#include <stdio.h>

void display() {
    auto int num = 10; // same as: int num = 10;

    printf("num = %d\n", num);
}

int main() {
    display();

    return 0;
}