// WAP to convert the capital letters of any string to small letter and vice-versa, finally print the changed string.

#include <stdio.h>

void toggleCase(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        // If the character is a lowercase letter, convert it to uppercase
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
        // If the character is an uppercase letter, convert it to lowercase
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
}

int main() {
    char str[200];

    // Input the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Call the toggleCase function to change the case of the string
    toggleCase(str);

    // Print the changed string
    printf("Changed string: %s\n", str);

    return 0;
}
