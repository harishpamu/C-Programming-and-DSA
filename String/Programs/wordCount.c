/*
 * Count number of words in a string using
 * different approaches.
 */

#include <stdio.h>

/*
 * Approach 1: Count Spaces
 *
 * Assumption:
 * String contains exactly one space between words
 * and no leading/trailing spaces.
 *
 * Example:
 * "Embedded Linux Device Driver"
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */
int countWordsSpaces(char str[]){
    int count = 1;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            count++;
        }
    }

    return count;
}

/*
 * Approach 2: State Machine
 *
 * Handles:
 *  - Multiple spaces
 *  - Leading spaces
 *  - Trailing spaces
 *
 * Idea:
 * Entering a word => count++
 *
 * Example:
 * "  Embedded   Linux  Device Driver  "
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */
int countWordsStateMachine(char str[]){
    int count = 0;
    int inWord = 0;

    for(int i = 0; str[i] != '\0'; i++){
        /*
         * Beginning of a new word
         */
        if(str[i] != ' ' && inWord == 0){
            count++;
            inWord = 1;
        }
        /*
         * Exiting a word
         */
        else if(str[i] == ' '){
            inWord = 0;
        }
    }

    return count;
}

int main(){
    char str[] = "  Embedded   Linux   Device Driver  ";
    printf("String : \"%s\"\n\n", str);

    printf("Spaces Count Method : %d\n", countWordsSpaces(str));
    printf("State Machine Method: %d\n", countWordsStateMachine(str));

    return 0;
}