/*
* Reverse words in a sentence.
*
* Input:
* Linux Device Driver
* Output:
* Driver Device Linux
*/
#include<stdio.h>
#include<string.h>

/*
* Approach:
* Tokenization using strtok()
*/
void reverseWords(char str[]){
    char *words[20];
    int count = 0;

    char *token = strtok(str, " ");
    while(token != NULL){
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    for(int i = count - 1; i >= 0; i--){
        printf("%s ", words[i]);
    }

    printf("\n");
}

int main(){
    char str[] = "Linux Device Driver";
    
    printf("Original : %s\n", str);
    printf("Reversed : ");
    reverseWords(str);
    return 0;
}