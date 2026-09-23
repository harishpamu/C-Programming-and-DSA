#include <stdio.h>

int main(){
    int temp = 35;
    char buffer[50];

    // Writes formatted data into string.
    sprintf(buffer, "Temperature = %d", temp);

    printf("%s\n", buffer);

    return 0;
}