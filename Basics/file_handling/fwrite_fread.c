/*
 * Binary file write and read.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

#include <stdio.h>

struct Student{
    int id;
    char name[20];
    float marks;
};

int main(){    
    FILE *fp;

    struct Student s1 ={
        101,
        "Harish",
        95.5
    };

    struct Student s2;

    fp = fopen("student.bin", "wb");
    if(fp == NULL){
        perror("fopen");
        return -1;
    }
    fwrite(&s1, sizeof(struct Student), 1, fp);
    fclose(fp);

    fp = fopen("student.bin", "rb");
    fread(&s2, sizeof(struct Student), 1, fp);

    fclose(fp);
    printf("ID    : %d\n", s2.id);
    printf("Name  : %s\n", s2.name);
    printf("Marks : %.2f\n", s2.marks);

    return 0;
}