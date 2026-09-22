#include<stdio.h>

struct Student {
    int roll;
    float marks;
};

void display(struct Student *s){
    printf("Roll: %d\n", s->roll);
    printf("Marks: %.2f\n", s->marks);
}

int main(){
    struct Student s = {
        .roll = 1, 
        .marks = 93.5
    };

    display(&s);

    return 0;
}