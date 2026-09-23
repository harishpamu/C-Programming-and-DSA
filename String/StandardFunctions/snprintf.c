#include <stdio.h>

int main(){
    int temp = 35;
    char buffer[20];

    /*
    * Safe version of sprintf().
    *
    * Prevents buffer overflow.
    */
    snprintf(buffer, sizeof(buffer), "Temp=%d", temp);

    printf("%s\n", buffer);

    return 0;
}