/*
 * Check whether two strings are anagrams.
 Anangram: Two strings are called anagrams if they contain the  same characters with the same frequency,
 irrespective of their order.
 */

#include <stdio.h>
#include <string.h>

/*
 * Approach:
 * Frequency Array
 *
 * Time  : O(n)
 * Space : O(256)
 */
int isAnagram(char str1[], char str2[]){
    int freq[256] = {0};

    if(strlen(str1) != strlen(str2)){
        return 0;
    }

    for(int i = 0; str1[i] != '\0'; i++){
        freq[(unsigned char)str1[i]]++;
        freq[(unsigned char)str2[i]]--;
    }

    for(int i = 0; i < 256; i++){
        if(freq[i] != 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    char str1[] = "listen";
    char str2[] = "silent";

    if(isAnagram(str1, str2)){
        printf("Anagram\n");
    } else{
        printf("Not Anagram\n");
    }

    return 0;
}