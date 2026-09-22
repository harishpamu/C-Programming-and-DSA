#include <stdio.h>

void display(void){   
    printf("Function code lives in text segment\n");
}

int main(){
    display();

    return 0;
}