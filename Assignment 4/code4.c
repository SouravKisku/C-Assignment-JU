#include <stdio.h>
#include <ctype.h>  // For the toupper function

// Function to convert all alphabets in the string to uppercase
void convertToUpper(char str[]) {
    int i = 0;
    // Loop through each character of the string until the null character is encountered
    while (str[i] != '\0') {
        // If the character is a lowercase letter, convert it to uppercase
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
}

int main() {
    char str[1000];

    // Input the string
    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin);

    // Call the function to convert the string to uppercase
    convertToUpper(str);

    // Print the modified string
    printf("Converted string: %s\n", str);

    return 0;
}
