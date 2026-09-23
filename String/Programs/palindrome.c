/*
 * Check whether a string is palindrome.
 *
 * Example:
 * madam -> Palindrome
 * hello -> Not Palindrome
 */

#include <stdio.h>
#include <string.h>

/*
 * Approach 1:
 * Two Pointer Technique
 *
 * Compare characters from both ends.
 *
 * Time  : O(n)
 * Space : O(1)
 */
int palindromeTwoPointer(char str[]){
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end){
        if(str[start] != str[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

/*
 * Approach 2:
 * Reverse String And Compare
 *
 * Time  : O(n)
 * Space : O(n)
 */
int palindromeReverseCompare(char str[]){
    char temp[100];
    strcpy(temp, str);

    int start = 0;
    int end = strlen(temp) - 1;

    while(start < end){
        char t = temp[start];
        temp[start] = temp[end];
        temp[end] = t;

        start++;
        end--;
    }
    return strcmp(str, temp) == 0;
}

int main()
{
    char str[] = "madam";

    printf("String : %s\n\n", str);
    printf("Two Pointer : %s\n", palindromeTwoPointer(str) ? "Palindrome" : "Not Palindrome");
    printf("Reverse Compare : %s\n", palindromeReverseCompare(str) ? "Palindrome" : "Not Palindrome");

    return 0;
}
