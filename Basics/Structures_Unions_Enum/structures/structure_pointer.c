#include<stdio.h>

struct Employee{
    int id;
    char grade;
    float salary;
};

int main(){
    struct Employee emp = {
        .id = 101,
        .grade = 'A',
        .salary = 50000.537
    };

    struct Employee *ptr = &emp;

    // Access pointer structure members using (->) operator.
    printf("ID : %d\n", ptr->id); // eqivalent to (*ptr).id
    printf("Grade : %c\n", ptr->grade);
    printf("Salary : %.2f\n", ptr->salary);

    return 0;
}