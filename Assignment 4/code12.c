#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the starting position of the second string in the first string
int findSubstring(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If second string is longer than the first, it can't be a substring
    if (len2 > len1) {
        return 0;
    }

    // Traverse the first string
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        // Compare the substring of length of str2 with the second string
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j]) {
                break;
            }
        }
        // If the whole second string matches
        if (j == len2) {
            return i + 1; // Return the starting position (1-based index)
        }
    }

    return 0; // If no match is found
}

int main() {
    char *str1, *str2;
    int len1, len2;

    // Input the lengths of the two strings
    printf("Enter the length of the first string: ");
    scanf("%d", &len1);
    printf("Enter the length of the second string: ");
    scanf("%d", &len2);

    // Dynamically allocate memory for the strings
    str1 = (char*)malloc((len1 + 1) * sizeof(char)); // +1 for null terminator
    str2 = (char*)malloc((len2 + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (str1 == NULL || str2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the strings
    printf("Enter the first string: ");
    getchar();  // to consume the newline character left by the previous scanf
    fgets(str1, len1 + 1, stdin);
    printf("Enter the second string: ");
    fgets(str2, len2 + 1, stdin);

    // Remove newline characters that fgets might add
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    // Call the function to find the second string in the first one
    int position = findSubstring(str1, str2);

    if (position == 0) {
        printf("The second string is not present in the first string.\n");
    } else {
        printf("The second string is present at position %d in the first string.\n", position);
    }

    // Free the allocated memory
    free(str1);
    free(str2);

    return 0;
}
