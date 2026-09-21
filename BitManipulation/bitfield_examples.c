#include<stdio.h>

struct Status{
    unsigned int ready : 1;
    unsigned int error : 1;
    unsigned int busy : 1;
    unsigned int res : 5;
};

int main(){
    struct Status s = {
        .ready = 1,
        .error = 0,
        .busy = 1,
        .res = 0
    };

    printf("ready=%u\n", s.ready);
    printf("error=%u\n", s.error);
    printf("busy=%u\n", s.busy);

    return 0;
}