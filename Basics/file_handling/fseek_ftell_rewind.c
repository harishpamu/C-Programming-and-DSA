/*
 * Demonstrates fill positioning APIs.
 *
 * APIs:
 * fseek()
 * ftell()
 * rewind()
 *
 * Time Complexity  : O(1)
 * Space Complexity : O(1)
*/

#include <stdio.h>

int main() {
    FILE *fp;
    long pos;

    fp = fopen("data.txt", "w+");

    if(fp == NULL){
        perror("fopen");
        return -1;
    }

    fputs("Embedded Linux", fp);

    fseek(fp, 5, SEEK_SET);
    pos = ftell(fp);

    printf("Position = %ld\n", pos);

    rewind(fp);

    printf("Position Afte* Rewind = %ld\n", ftell(fp));

    fclose(fp);

    return 0;
}