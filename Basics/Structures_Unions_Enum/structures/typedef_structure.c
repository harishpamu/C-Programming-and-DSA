#include<stdio.h>

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct{
    int id;
    float salary;
}Employee;

int main(){
    u32 count = 100;
    u8 grade = 'A';

    printf("count = %u\n", count);
    printf("grade = %c\n", grade);

    Employee emp;

    emp.id = 1;
    emp.salary = 50000;

    printf("%d, %.2f\n", emp.id, emp.salary);

    return 0;
}