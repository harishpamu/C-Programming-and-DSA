/*
 * Write and read strings.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

#include <stdio.h>

int main(){
    FILE *fp;
    char buffer[100];

    fp = fopen("string.txt", "w");
    if(fp == NULL){
        perror("fopen");
        return -1;
    }

    fputs("Embedded Linux\n", fp);
    fputs("Device Driver\n", fp);

    fclose(fp);

    fp = fopen("string.txt", "r");
    printf("File Contents:\n");

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}