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

    // Access structure members using (.) operator.
    printf("ID : %d\n", emp.id);
    printf("Grade : %c\n", emp.grade);
    printf("Salary : %.2f\n", emp.salary);

    return 0;
}