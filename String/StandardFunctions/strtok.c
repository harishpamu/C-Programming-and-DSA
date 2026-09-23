#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "10,20,30,40";

    /*
    * Splits string using delimiter.
    *
    * Commonly used in:
    * - CSV Parsing
    * - Command Parsing
    * - Protocol Handling
    */
    char *token = strtok(str, ",");

    while(token != NULL)
    {
        printf("%s\n", token);

        token = strtok(NULL, ",");
    }

    return 0;
}