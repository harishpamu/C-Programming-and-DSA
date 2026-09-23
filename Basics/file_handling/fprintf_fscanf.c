/*
 * Demonstrates formatted file write/read.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

#include <stdio.h>

int main(){
    FILE *fp;

    char name[20];
    int age;

    fp = fopen("employee.txt", "w");

    if(fp == NULL){
        perror("fopen");
        return -1;
    }

    fprintf(fp, "Harish 25\n");
    fclose(fp);

    fp = fopen("employee.txt", "r");
    if(fp == NULL){
        perror("fopen");
        return -1;
    }

    fscanf(fp, "%s %d", name, &age);

    printf("Name : %s\n", name);
    printf("Age  : %d\n", age);

    fclose(fp);

    return 0;
}