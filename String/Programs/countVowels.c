/*
 * Count:
 * 1. Vowels
 * 2. Consonants
 * 3. Digits
 * 4. Spaces
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */
#include<stdio.h>
#include<ctype.h>

int main(){
    char str[] = "Embedded Linux 123";

    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;

    /*
     * Traverse entire string once
     */
    for(int i = 0; str[i] != '\0'; i++){
        /*
         * Convert uppercase to lowercase
         * for easier comparison.
         */
        char ch = tolower(str[i]);

        /*
         * Check alphabet
         */
        if(ch >= 'a' && ch <= 'z'){
            /*
             * Check vowel
             */
            if(ch == 'a' ||
               ch == 'e' ||
               ch == 'i' ||
               ch == 'o' ||
               ch == 'u'){
                vowels++;
            } else{
                consonants++;
            }
        }
        /*
         * Check digit
         */
        else if(ch >= '0' && ch <= '9'){
            digits++;
        }
        /*
         * Check space
         */
        else if(ch == ' '){
            spaces++;
        }
    }

    printf("String      : %s\n", str);
    printf("Vowels      : %d\n", vowels);
    printf("Consonants  : %d\n", consonants);
    printf("Digits      : %d\n", digits);
    printf("Spaces      : %d\n", spaces);

    return 0;
}