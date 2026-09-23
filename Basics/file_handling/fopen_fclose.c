/* opening and closing a file.
 *
 * Time Complexity  : O(1)
 * Space Complexity : O(1)
 */

#include <stdio.h>

int main(){
    FILE *fp;

    fp = fopen("test.txt", "w");
    if(fp == NULL){
        perror("fopen");
        return -1;
    }
    printf("File opened successfully\n");
    
    fclose(fp);
    printf("File closed successfully\n");

    return 0;
}
