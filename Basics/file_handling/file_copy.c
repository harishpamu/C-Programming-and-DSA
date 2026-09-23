/*
 * Copy contents from a source file
 * to a destination file.
 *
 * Steps:
 * 1. Open source file in read mode.
 * 2. Open destination file in write mode.
 * 3. Read one character at a time.
 * 4. Write character into destination file.
 * 5. Close both files.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 *
 * where:
 * n = number of characters in source file
 */

#include <stdio.h>

int main(){
    FILE *src;
    FILE *dest;

    int ch;

    /* Open source file */
    src = fopen("source.txt", "r");
    if(src == NULL){
        perror("source file");
        return -1;
    }

    /* Open destination file */
    dest = fopen("destination.txt", "w");
    if(dest == NULL){
        perror("destination file");
        fclose(src);
        return -1;
    }

    /*
     * Read one character from source
     * and write it into destination.
     */
    while((ch = fgetc(src)) != EOF){
        fputc(ch, dest);
    }

    /* Close files */
    fclose(src);
    fclose(dest);

    printf("File copied successfully\n");
    return 0;
}