#include <stdio.h>
#include <string.h>

int main(){
    char dest[50] = "Embedded ";

    // Appends source string to destination
    strcat(dest, "Linux");
    printf("%s\n", dest);

   return 0;
}