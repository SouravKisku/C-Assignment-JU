// Write a menu driven program, consisting of following functions (on string),without using any library functions :--
// Strlen()          
// Strcpy()
// Strcat()
// Strrev()
// Strcmp()


#include <stdio.h>

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
    dest[i] = '\0';  // Null-terminate the destination string
}

// Function to concatenate two strings
void Strcat(char dest[], char src[]) {
    int i = 0, j = 0;
    
    // Move to the end of the destination string
    while (dest[i] != '\0') {
        i++;
    }
    
    // Append the source string to the destination string
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';  // Null-terminate the resulting string
}

// Function to reverse a string
void Strrev(char str[]) {
    int start = 0, end = Strlen(str) - 1;
    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to compare two strings
int Strcmp(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];  // If both strings are equal, this will return 0
}

int main() {
    int choice;
    char str1[100], str2[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Strlen()\n");
        printf("2. Strcpy()\n");
        printf("3. Strcat()\n");
        printf("4. Strrev()\n");
        printf("5. Strcmp()\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);  // Get the input string
                str1[Strlen(str1) - 1] = '\0';  // Remove the newline character
                printf("Length of the string is: %d\n", Strlen(str1));
                break;

            case 2:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[Strlen(str1) - 1] = '\0';
                printf("Enter destination string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[Strlen(str2) - 1] = '\0';
                Strcpy(str2, str1);
                printf("Destination string after copying: %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[Strlen(str1) - 1] = '\0';
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[Strlen(str2) - 1] = '\0';
                Strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[Strlen(str1) - 1] = '\0';
                Strrev(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 5:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[Strlen(str1) - 1] = '\0';
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[Strlen(str2) - 1] = '\0';
                int result = Strcmp(str1, str2);
                if (result == 0)
                    printf("Strings are equal\n");
                else if (result < 0)
                    printf("First string is less than second string\n");
                else
                    printf("First string is greater than second string\n");
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
