#include <stdio.h>

int main(){
    char *name[] = {
        "Embedded",
        "Linux",
        "Driver"
    };

    for(int i = 0; i < 3; i++){
        printf("%s\n", name[i]);
    }

    return 0;
}