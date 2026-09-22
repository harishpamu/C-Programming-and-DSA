#include<stdio.h>
#include<stdlib.h>

struct Employee{
    int id;
    float salary;
};

int main(){
    struct Employee *emp = (struct Employee *)malloc(sizeof(struct Employee));
    if(emp == NULL){
        printf("Allocation Failed\n");
        return 1;
    }

    emp->id = 101;
    emp->salary = 100000;

    printf("ID=%d\n", emp->id);
    printf("Salary=%.2f\n", emp->salary);

    free(emp);
    return 0;
}