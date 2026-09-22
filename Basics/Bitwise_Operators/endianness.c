#include<stdio.h>

int isLittleEndian(void){
    unsigned int num = 1;
    return *((char*)&num) == 1;
}

int main(){
    if(isLittleEndian()){
        printf("Little Endian\n");
    } else{
        printf("Big Endian\n");
    }
}