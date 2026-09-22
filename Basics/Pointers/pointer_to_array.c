#include <stdio.h>

int main(){
    int nums[5] = {1,2,3,4,5};
    int (*arrPtr)[5] = &nums;

    printf("(*arrPtr)[2] = %d\n", (*arrPtr)[2]);
    return 0;
}