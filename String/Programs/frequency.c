/*
 * Description:
 * Count character frequencies.
 */

#include <stdio.h>
#include <string.h>

/*
 * Approach 1:
 * Brute Force
 *
 * Time : O(n²)
 */
void frequencyBruteForce(char str[]){
    int visited[100] = {0};

    printf("Brute Force Method\n");
    for(int i = 0; str[i] != '\0'; i++){
        if(visited[i]){
            continue;
        }

        int count = 1;

        for(int j = i + 1; str[j] != '\0'; j++){
            if(str[i] == str[j]){
                count++;
                visited[j] = 1;
            }
        }

        printf("%c = %d\n", str[i], count);
    }
}

/*
 * Approach 2:
 * Frequency Array
 *
 * Time : O(n)
 */
void frequencyArray(char str[]){
    int freq[256] = {0};

    for(int i = 0; str[i] != '\0'; i++){
        freq[(unsigned char)str[i]]++;
    }

    printf("\nFrequency Array Method\n");

    for(int i = 0; i < 256; i++){
        if(freq[i]){
            printf("%c = %d\n", i, freq[i]);
        }
    }
}

int main()
{
    char str[] = "embedded";

    frequencyBruteForce(str);
    frequencyArray(str);

    return 0;
}