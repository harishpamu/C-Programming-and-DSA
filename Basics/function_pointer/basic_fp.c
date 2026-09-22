#include<stdio.h>

// int add(int a, int b){
//     return a + b;
// }

// int main(){
//     int (*fp)(int, int);
//     fp = add;

//     printf("%d\n", fp(10, 20));

//     return 0;
// }

void display(void)
{
    printf("Hello from display()\n");
}

int main()
{
    /* Function Pointer Declaration */
    void (*fp)(void);

    /* Store function address */
    fp = display;

    printf("Function Address = %p\n", fp);

    /* Call function using pointer */
    fp();

    return 0;
}