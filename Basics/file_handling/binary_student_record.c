#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float marks;
};

int main(){
    FILE *fp;

    struct Student students[3] = {
        {101, "Harish", 90.5},
        {102, "Ravi",   88.0},
        {103, "Kiran",  92.0}
    };

    fp = fopen("records.bin", "wb");

    if(fp == NULL){
        perror("fopen");
        return -1;
    }

    fwrite(students, sizeof(struct Student), 3, fp);
    fclose(fp);

    fp = fopen("records.bin", "rb");

    struct Student temp;

    printf("Student Records\n\n");

    while(fread(&temp, sizeof(struct Student), 1,fp) == 1){
        printf("ID    : %d\n", temp.id);
        printf("Name  : %s\n", temp.name);
        printf("Marks : %.2f\n\n", temp.marks);
    }
    fclose(fp);

    return 0;
}