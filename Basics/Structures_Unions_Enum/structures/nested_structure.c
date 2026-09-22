#include<stdio.h>

struct Address{
    char city[20];
    int pincode;
};

struct Employee{
    int id;
    struct Address addr;
};

int main(){
    struct Employee emp = {
        .id = 101,
        .addr = {"Hyderabad", 500001}
    };

    printf("ID : %d\n", emp.id);
    printf("City : %s\n", emp.addr.city);
    printf("Pincode : %d\n", emp.addr.pincode);

    return 0;
}