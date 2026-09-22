#include <stdio.h>

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}

int main()
{
    int choice;
    int a = 20;
    int b = 10;

    int (*operation)(int, int);

    printf("1. Add\n");
    printf("2. Sub\n");
    printf("3. Mul\n");
    printf("4. Div\n");

    printf("Enter Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            operation = add;
            break;

        case 2:
            operation = sub;
            break;

        case 3:
            operation = mul;
            break;

        case 4:
            operation = div;
            break;

        default:
            printf("Invalid Choice\n");
            return 0;
    }

    printf("Result = %d\n", operation(a, b));

    return 0;
}