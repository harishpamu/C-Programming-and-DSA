#include"arrayadt.h"

int main()
{
    Array a = {{10, 20, 30, 40, 50}, 5};
    display(a);

    append(&a, 60);
    display(a);

    insert(&a, 2, 25);
    display(a);

    delete_value(&a, 3);
    display(a);

    printf("Search 40 = %d\n", search(a, 40));

    printf("Get index 2 = %d\n", get(a, 2));

    set(&a, 1, 100);
    display(a);

    printf("Min = %d\n", min(a));
    printf("Max = %d\n", max(a));

    reverse(&a);
    display(a);

    rotateLeft(&a);
    display(a);

    rotateRight(&a);
    display(a);

    return 0;
}
