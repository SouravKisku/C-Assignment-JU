#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

// Define a structure for a linked list node
typedef struct Node {
    char word[MAX_STRING_LENGTH];
    struct Node *next;
} Node;

// Function prototypes
char *stripNonAlphabetic(const char *str);
int isPalindrome(const char *str);
void insertAlphabetically(Node **head, const char *word);
void saveToBinaryFile(Node *head, const char *filename);
void freeList(Node *head);

int main() {
    char inputFile[] = "strings.txt";
    char outputFile[] = "palindromes.bin";
    FILE *file = fopen(inputFile, "r");

    if (!file) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    // Initialize the linked list
    Node *head = NULL;

    // Read strings from the file
    char buffer[MAX_STRING_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        // Strip non-alphabetic characters
        char *stripped = stripNonAlphabetic(buffer);

        // Check if the stripped string is a palindrome
        if (isPalindrome(stripped)) {
            // Insert the palindrome into the linked list in alphabetical order
            insertAlphabetically(&head, stripped);
        }

        free(stripped);
    }
    fclose(file);

    // Save the linked list to a binary file
    saveToBinaryFile(head, outputFile);

    // Free the linked list
    freeList(head);

    printf("Palindromes saved to '%s'.\n", outputFile);
    return EXIT_SUCCESS;
}

// Function to strip non-alphabetic characters from a string
char *stripNonAlphabetic(const char *str) {
    char *result = (char *)malloc(MAX_STRING_LENGTH);
    if (!result) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha((unsigned char)str[i])) {
            result[j++] = tolower((unsigned char)str[i]);
        }
    }
    result[j] = '\0';
    return result;
}

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

// Function to insert a word into the linked list in alphabetical order
void insertAlphabetically(Node **head, const char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->word, word, MAX_STRING_LENGTH);
    newNode->word[MAX_STRING_LENGTH - 1] = '\0';
    newNode->next = NULL;

    if (!*head || strcmp(word, (*head)->word) < 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next && strcmp(word, current->next->word) > 0) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to save the linked list to a binary file
void saveToBinaryFile(Node *head, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    Node *current = head;
    while (current) {
        fwrite(current->word, sizeof(char), MAX_STRING_LENGTH, file);
        current = current->next;
    }

    fclose(file);
}

// Function to free the linked list
void freeList(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
