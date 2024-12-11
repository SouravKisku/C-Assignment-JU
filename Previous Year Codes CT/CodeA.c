#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for linked list nodes
typedef struct Node {
    char name[50];
    struct Node *next;
} Node;

// Function prototypes
Node *createNode(const char *name);
void appendNode(Node **head, const char *name);
void saveListToFile(Node *head, const char *filename, int count);
void freeList(Node *head);

int main() {
    char inputFile[] = "names.txt";
    char outputFile[] = "linked_list.bin";
    FILE *file = fopen(inputFile, "r");

    if (!file) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    // Read names from the file
    char buffer[1024];
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Failed to read from file");
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);

    // Split names by comma
    char *names[100];
    int count = 0;
    char *token = strtok(buffer, ",");
    while (token) {
        names[count++] = strdup(token);
        token = strtok(NULL, ",");
    }

    // Pick a random starting name
    srand(time(NULL));
    int randomIndex = rand() % count;

    // Create the linked list
    Node *head = NULL;
    appendNode(&head, names[randomIndex]);
    for (int i = 0; i < count; i++) {
        if (i != randomIndex) {
            appendNode(&head, names[i]);
        }
    }

    // Save the linked list to a binary file
    saveListToFile(head, outputFile, count);

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(names[i]);
    }
    freeList(head);

    printf("Linked list saved to '%s' with %d items.\n", outputFile, count);
    return EXIT_SUCCESS;
}

// Function to create a new node
Node *createNode(const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(Node **head, const char *name) {
    Node *newNode = createNode(name);
    if (!*head) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to save the linked list to a binary file
void saveListToFile(Node *head, const char *filename, int count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    // Write the word count
    fwrite(&count, sizeof(int), 1, file);

    // Write the linked list
    Node *current = head;
    while (current) {
        fwrite(current->name, sizeof(char), sizeof(current->name), file);
        current = current->next;
    }

    fclose(file);
}

// Function to free the linked list
void freeList(Node *head) {
    Node *current = head;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}
