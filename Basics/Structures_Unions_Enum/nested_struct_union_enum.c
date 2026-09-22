#include <stdio.h>
#include <string.h>

/* Enum for employee status */
typedef enum
{
    INACTIVE = 0,
    ACTIVE,
    ON_LEAVE
}EmployeeStatus;

/* Nested Structure */
typedef struct
{
    char city[20];
    int pincode;
}Address;

/* Union for contact information */
typedef union
{
    long mobile;
    char email[30];
}ContactInfo;

/* Main Structure */
typedef struct
{
    int id;
    char grade;

    Address addr;         // Nested Structure
    ContactInfo contact;  // Union
    EmployeeStatus status;// Enum
}Employee;

int main()
{
    Employee emp;

    /* Basic Members */
    emp.id = 101;
    emp.grade = 'A';

    /* Nested Structure Members */
    strcpy(emp.addr.city, "Bangalore");
    emp.addr.pincode = 560001;

    /* Union Member */
    emp.contact.mobile = 9876543210;

    /* Enum Member */
    emp.status = ACTIVE;

    printf("Employee Details\n");
    printf("-------------------------\n");

    printf("ID       : %d\n", emp.id);
    printf("Grade    : %c\n", emp.grade);

    printf("\nAddress Information\n");
    printf("City     : %s\n", emp.addr.city);
    printf("Pincode  : %d\n", emp.addr.pincode);

    printf("\nContact Information\n");
    printf("Mobile   : %ld\n", emp.contact.mobile);

    printf("\nStatus Information\n");

    switch(emp.status)
    {
        case INACTIVE:
            printf("Status   : INACTIVE\n");
            break;

        case ACTIVE:
            printf("Status   : ACTIVE\n");
            break;

        case ON_LEAVE:
            printf("Status   : ON_LEAVE\n");
            break;
    }

    return 0;
}