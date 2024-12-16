#include <stdio.h>

#define MAX 100  // Maximum length for the string

// Function to calculate the length of a string
int Strlen(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to copy one string to another
void Strcpy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Null-terminate the copied string
}

// Function to concatenate two strings
void Strcat(char dest[], char src[]) {
    int i = Strlen(dest);  // Find the length of the destination string
    int j = 0;
    
    // Append the source string to the destination string
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';  // Null-terminate the concatenated string
}

// Function to reverse a string
void Strrev(char str[]) {
    int start = 0;
    int end = Strlen(str) - 1;
    char temp;

    // Swap characters from both ends towards the center
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to compare two strings
int Strcmp(char str1[], char str2[]) {
    int i = 0;
    
    // Compare characters one by one
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    // If both strings end at the same time, they are equal
    return str1[i] - str2[i];
}

int main() {
    int choice;
    char str1[MAX], str2[MAX], result[MAX];

    do {
        // Menu
        printf("\nMenu:\n");
        printf("1. Strlen() - Calculate string length\n");
        printf("2. Strcpy() - Copy one string to another\n");
        printf("3. Strcat() - Concatenate two strings\n");
        printf("4. Strrev() - Reverse a string\n");
        printf("5. Strcmp() - Compare two strings\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after choice input
        
        switch(choice) {
            case 1:
                // Strlen()
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                printf("Length of the string: %d\n", Strlen(str1) - 1);  // Subtract 1 to exclude newline
                break;
            case 2:
                // Strcpy()
                printf("Enter the source string: ");
                fgets(str1, sizeof(str1), stdin);
                Strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
            case 3:
                // Strcat()
                printf("Enter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                Strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 4:
                // Strrev()
                printf("Enter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                Strrev(str1);
                printf("Reversed string: %s\n", str1);
                break;
            case 5:
                // Strcmp()
                printf("Enter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                int resultCmp = Strcmp(str1, str2);
                if (resultCmp == 0) {
                    printf("Strings are equal.\n");
                } else if (resultCmp < 0) {
                    printf("First string is less than second string.\n");
                } else {
                    printf("First string is greater than second string.\n");
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}
