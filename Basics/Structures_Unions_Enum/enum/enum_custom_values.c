#include <stdio.h>

enum Status {
    SUCCESS = 0,
    FAIL = -1,
    BUSY = 1,
    TIMEOUT = 2
};

int main(){
    enum Status ret = SUCCESS;

    printf("Status = %d\n", ret);

    return 0;
}