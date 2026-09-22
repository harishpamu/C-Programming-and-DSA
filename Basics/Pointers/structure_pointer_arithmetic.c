#include <stdio.h>

struct Student{
    int id;
    char name[20];
};

int main(){
    struct Student students[] =
    {
        {101,"Harish"},
        {102,"Linux"}
    };

    struct Student *ptr = students;
    printf("%d %s\n", ptr->id, ptr->name);

    ptr++;
    printf("%d %s\n", ptr->id, ptr->name);

    return 0;
}