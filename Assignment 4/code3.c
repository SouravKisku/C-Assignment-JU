#include <stdio.h>
#include <string.h>

// Non-recursive (Iterative) function to reverse the string
void reverseNonRecursive(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    // Swap characters from both ends until the middle of the string is reached
    while (start < end) {
        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

// Recursive function to reverse the string
void reverseRecursive(char str[], int start, int end) {
    // Base case: If start >= end, return (stop recursion)
    if (start >= end) {
        return;
    }

    // Swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for the next pair of characters
    reverseRecursive(str, start + 1, end - 1);
}

int main() {
    char str[100];

    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Copy of original string for recursive reversal
    char strRecursive[100];
    strcpy(strRecursive, str);

    // Reverse the string non-recursively and print
    reverseNonRecursive(str);
    printf("Reversed string (non-recursive): %s\n", str);

    // Reverse the string recursively and print
    reverseRecursive(strRecursive, 0, strlen(strRecursive) - 1);
    printf("Reversed string (recursive): %s\n", strRecursive);

    return 0;
}
