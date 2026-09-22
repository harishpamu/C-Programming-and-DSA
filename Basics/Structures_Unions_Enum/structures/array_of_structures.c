#include<stdio.h>

struct Student{
    int roll;
    float marks;
};

int main(){
    struct Student s[3] = {
        {101, 90.5},
        {102, 88.7},
        {103, 78}
    };

    for(int i = 0; i < 3; i++){
        printf("Roll: %d, marks: %.2f\n", s[i].roll, s[i].marks);
    }

    return 0;
}