//WAP to take a line of text then convert all the alphabets of it to uppercase.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToUppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char str[100];

    // Input the line of text
    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    // Convert to uppercase
    convertToUppercase(str);

    // Print the converted text
    printf("Text in uppercase: %s\n", str);

    return 0;
}
