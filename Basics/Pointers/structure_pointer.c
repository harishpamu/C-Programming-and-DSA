#include <stdio.h>

struct Student{
    int id;
    char name[20];
};

int main(){
    struct Student s = {
        .id = 101,
        .name = "Harish"
    };
    struct Student *sptr = &s;
    printf("ID   : %d\n", sptr->id);
    printf("Name : %s\n", sptr->name);

    return 0;
}