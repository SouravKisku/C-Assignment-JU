#include <stdio.h>
#include <ctype.h>

void Vowel_Cons_Count(char str[], int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    
    // Traverse the string
    for (int i = 0; str[i] != '#'; i++) {
        char ch = tolower(str[i]); // Convert character to lowercase
        
        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            (*vowels)++;
        }
        // Check if the character is a consonant (alphabetic and not a vowel)
        else if ((ch >= 'a' && ch <= 'z')) {
            (*consonants)++;
        }
    }
}

int main() {
    char str[1000];
    int vowels = 0, consonants = 0;

    // Input a line of text
    printf("Enter a line of text (terminated by #): ");
    fgets(str, sizeof(str), stdin);

    // Call the function to count vowels and consonants
    Vowel_Cons_Count(str, &vowels, &consonants);

    // Print the results
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
