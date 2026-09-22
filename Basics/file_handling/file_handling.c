#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[20];
    float marks;
};

int main()
{
    FILE *fp;
    char ch;
    char buffer[100];

    /*-------------------------------------------------
      1. fprintf() - Write formatted data
    -------------------------------------------------*/
    fp = fopen("text.txt", "w");
    if(fp == NULL){
        printf("File open failed\n");
        return 1;
    }

    fprintf(fp, "Harish 95\n");
    fprintf(fp, "Embedded C\n");

    fclose(fp);

    printf("fprintf() completed\n");

    /*-------------------------------------------------
      2. fscanf() - Read formatted data
    -------------------------------------------------*/
    char name[20];
    int marks;

    fp = fopen("text.txt", "r");

    fscanf(fp, "%s %d", name, &marks);

    printf("\nName  : %s\n", name);
    printf("Marks : %d\n", marks);

    fclose(fp);

    /*-------------------------------------------------
      3. fputc() - Write character
    -------------------------------------------------*/
    fp = fopen("char.txt", "w");

    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);

    fclose(fp);

    printf("\nfputc() completed\n");

    /*-------------------------------------------------
      4. fgetc() - Read character
    -------------------------------------------------*/
    fp = fopen("char.txt", "r");

    printf("\nReading using fgetc(): ");

    while((ch = fgetc(fp)) != EOF){
        printf("%c ", ch);
    }

    fclose(fp);

    /*-------------------------------------------------
      5. fputs() - Write string
    -------------------------------------------------*/
    fp = fopen("string.txt", "w");

    fputs("Linux Device Driver\n", fp);
    fputs("Embedded C Programming\n", fp);

    fclose(fp);

    printf("\nfputs() completed\n");

    /*-------------------------------------------------
      6. fgets() - Read string
    -------------------------------------------------*/
    fp = fopen("string.txt", "r");
    printf("\nReading using fgets():\n");

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        printf("%s", buffer);
    }

    fclose(fp);

    /*-------------------------------------------------
      7. fwrite() - Binary write
    -------------------------------------------------*/
    struct Student s1 = {
        101,
        "Harish",
        95.5
    };

    fp = fopen("student.bin", "wb");

    fwrite(&s1, sizeof(struct Student), 1, fp);

    fclose(fp);

    printf("\nfwrite() completed\n");

    /*-------------------------------------------------
      8. fread() - Binary read
    -------------------------------------------------*/
    struct Student s2;

    fp = fopen("student.bin", "rb");

    fread(&s2,
          sizeof(struct Student),
          1,
          fp);

    fclose(fp);

    printf("\nData from Binary File\n");
    printf("ID    : %d\n", s2.id);
    printf("Name  : %s\n", s2.name);
    printf("Marks : %.2f\n", s2.marks);

    /*-------------------------------------------------
      9. ftell()
    -------------------------------------------------*/
    fp = fopen("string.txt", "r");

    fseek(fp, 5, SEEK_SET);

    printf("\nCurrent Position = %ld\n",
           ftell(fp));

    /*-------------------------------------------------
      10. rewind()
    -------------------------------------------------*/
    rewind(fp);

    printf("Position after rewind = %ld\n",
           ftell(fp));

    fclose(fp);

    /*-------------------------------------------------
      11. fseek()
    -------------------------------------------------*/
    fp = fopen("string.txt", "r");

    fseek(fp, 7, SEEK_SET);

    ch = fgetc(fp);

    printf("\nCharacter at Position 7 = %c\n", ch);

    fclose(fp);

    return 0;
}