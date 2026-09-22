#include<stdio.h>

/*
 * A structure groups different data types into one object.
*/
struct Employee{
    int id;
    char grade;
    float salary;
};

int main(){
    struct Employee emp;

    emp.id = 101;
    emp.grade = 'A';
    emp.salary = 5000.10;

    printf("ID : %d\n", emp.id);
    printf("Grade : %c\n", emp.grade);
    printf("Salary : %.2f\n", emp.salary);

    return 0;
}