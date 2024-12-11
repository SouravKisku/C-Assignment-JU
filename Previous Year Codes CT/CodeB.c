#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode a character (simple Caesar cipher for example)
char encode_char(char c) {
    return c + 3;  // Shift character by 3 for encoding
}

// Function to decode a character
char decode_char(char c) {
    return c - 3;  // Reverse the shift for decoding
}

// Function to encode the file and save it in a binary file with line length information
void encode_file(const char *source_filename, const char *binary_filename) {
    FILE *source_file = fopen(source_filename, "r");
    FILE *binary_file = fopen(binary_filename, "wb");
    char line[1000];
    
    if (source_file == NULL || binary_file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    while (fgets(line, sizeof(line), source_file)) {
        int line_length = strlen(line);
        // Encode each character in the line
        for (int i = 0; i < line_length; i++) {
            line[i] = encode_char(line[i]);
        }
        
        // Write the length of the line followed by the encoded line to the binary file
        fwrite(&line_length, sizeof(int), 1, binary_file);
        fwrite(line, sizeof(char), line_length, binary_file);
    }
    
    fclose(source_file);
    fclose(binary_file);
    printf("File encoded and saved to binary file %s\n", binary_filename);
}

// Function to decode the file and reconstruct the original code
void decode_file(const char *binary_filename, const char *output_filename) {
    FILE *binary_file = fopen(binary_filename, "rb");
    FILE *output_file = fopen(output_filename, "w");
    int line_length;
    char *line;
    
    if (binary_file == NULL || output_file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    line = (char *)malloc(1000 * sizeof(char));
    if (line == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    while (fread(&line_length, sizeof(int), 1, binary_file)) {
        fread(line, sizeof(char), line_length, binary_file);
        
        // Decode each character in the line
        for (int i = 0; i < line_length; i++) {
            line[i] = decode_char(line[i]);
        }
        
        // Write the decoded line to the output file
        fwrite(line, sizeof(char), line_length, output_file);
    }
    
    free(line);
    fclose(binary_file);
    fclose(output_file);
    printf("File decoded and saved to %s\n", output_filename);
}

// Main function to show menu and execute corresponding actions
int main() {
    int choice;
    char source_filename[100], binary_filename[100], output_filename[100];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Encode a C-source file\n");
        printf("2. Decode the binary file to original C-source code\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after entering the choice
        
        switch (choice) {
            case 1:
                printf("Enter the source C-file name to encode: ");
                fgets(source_filename, sizeof(source_filename), stdin);
                source_filename[strcspn(source_filename, "\n")] = '\0';  // Remove newline
                printf("Enter the binary file name to save the encoded file: ");
                fgets(binary_filename, sizeof(binary_filename), stdin);
                binary_filename[strcspn(binary_filename, "\n")] = '\0';  // Remove newline
                encode_file(source_filename, binary_filename);
                break;
                
            case 2:
                printf("Enter the binary file name to decode: ");
                fgets(binary_filename, sizeof(binary_filename), stdin);
                binary_filename[strcspn(binary_filename, "\n")] = '\0';  // Remove newline
                printf("Enter the output file name to save the decoded content: ");
                fgets(output_filename, sizeof(output_filename), stdin);
                output_filename[strcspn(output_filename, "\n")] = '\0';  // Remove newline
                decode_file(binary_filename, output_filename);
                break;
                
            case 3:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
