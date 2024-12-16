// WAP to take one string then  print it in the reverse order and check whether the input string is Plindrome.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverseString(char str[], char reversed[]) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0'; // Null-terminate the reversed string
}

bool isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100], reversed[100];

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    // Reverse the string
    reverseString(str, reversed);

    // Check if the string is a palindrome
    bool palindrome = isPalindrome(str);

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Print whether the string is a palindrome
    if (palindrome) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}
