// WAP to Write the number of vowels & consonants of any entered line of  any input string.	 	 
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void countVowelsAndConsonants(char str[], int *vowelCount, int *consonantCount) {
    *vowelCount = 0;
    *consonantCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowelCount)++;
            } else {
                (*consonantCount)++;
            }
        }
    }
}

int main() {
    char str[100];
    int vowels, consonants;

    // Input the string
    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    // Count vowels and consonants
    countVowelsAndConsonants(str, &vowels, &consonants);

    // Print the results
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
