/*
 * Write and read characters
 * one byte at a time.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

#include <stdio.h>

int main(){
    FILE *fp;
    int ch;

    fp = fopen("char.txt", "w");
    if(fp == NULL){
        perror("fopen");
        return -1;
    }

    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);

    fclose(fp);

    fp = fopen("char.txt", "r");
    printf("Reading File:\n");
    while((ch = fgetc(fp)) != EOF){
        printf("%c ", ch);
    }
    printf("\n");

    fclose(fp);

    return 0;
}