#include<stdio.h>

/*
* Frequency Array
*
* Time : O(n)
* Space : O(256)
*/
void removeDuplicates(char str[]){
    int hash[256] = {0};
    int i = 0;
    int j = 0;

    for(i = 0; str[i] != '\0'; i++){
        if(hash[(unsigned char)str[i]] == 0){
            hash[(unsigned char)str[i]] = 1;

            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void printDuplicates(char str[]){
    /*
    for(int i = 0; str[i] != '\0'; i++){
        int count = 1;
        for(int j = i + 1; str[j] != '\0'; j++){
            if(str[i] == str[j]){
                count++;
            }
        }

        if(count > 1){
            printf("%c ", str[i]);
        }
    }
    */
    int hash[256] = {0};
    for(int i = 0; str[i] != '\0'; i++){
        hash[(unsigned char)str[i]]++;
    }

    for(int i = 0; i < 256; i++){
        if(hash[i] > 1){
            printf("%c ", i);
        }
    }
}

int main(){
    char str[] = "HAHA";
    printDuplicates(str);
    printf("\n");

    removeDuplicates(str);
    printf("%s\n", str);

    return 0;
}