#include <stdio.h>
#include <stdlib.h>

void generateFiles(int numberOfFiles) {
    char fileName[20];
    for (int i = 1; i <= numberOfFiles; i++) {
        // Generate the file name
        sprintf(fileName, "code%d.c", i);

        // Open the file for writing
        FILE *file = fopen(fileName, "w");
        if (file == NULL) {
            printf("Error: Could not create file %s\n", fileName);
            continue;
        }

        // Write a basic template to the file
        fprintf(file, "#include <stdio.h>\n\nint main() {\n    printf(\"Hello from %s\\n\");\n    return 0;\n}\n", fileName);

        // Close the file
        fclose(file);
        printf("File %s created successfully.\n", fileName);
    }
}

int main() {
    int numberOfFiles;

    // Ask the user for the number of files to create
    printf("Enter the number of C files to generate: ");
    scanf("%d", &numberOfFiles);

    // Validate input
    if (numberOfFiles <= 0) {
        printf("Invalid number of files. Please enter a positive integer.\n");
        return 1;
    }

    // Generate the files
    generateFiles(numberOfFiles);

    return 0;
}
