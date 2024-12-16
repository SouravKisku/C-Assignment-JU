// WAP to take one 2-D array, find the transpose of  it, finally print the multiplied value of the matrix with its transpose.
//Code14 is still showing Error
//To be fixed
#include <stdio.h>
#include <stdlib.h>

// Function to find the transpose of a matrix
void transpose(int** matrix, int** transpose, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply(int** matrix, int** transpose, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix[i][k] * transpose[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Taking input for the matrix dimensions
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Dynamically allocating memory for the matrix, its transpose, and the result
    int** matrix = (int**)malloc(rows * sizeof(int*));
    int** transpose = (int**)malloc(cols * sizeof(int*));  // Transpose has cols rows and rows cols
    int** result = (int**)malloc(rows * sizeof(int*));

    // Check if memory allocation was successful
    if (matrix == NULL || transpose == NULL || result == NULL) {
        printf("Memory allocation failed.\n");
        return -1;  // Exit if memory allocation fails
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        result[i] = (int*)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < cols; i++) {
        transpose[i] = (int*)malloc(rows * sizeof(int));  // Transpose matrix has cols rows
    }

    // Taking input for the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Finding the transpose of the matrix
    transpose(matrix, transpose, rows, cols);

    // Multiplying the matrix with its transpose
    multiply(matrix, transpose, result, rows, cols);

    // Displaying the result of the multiplication
    printf("\nResult of multiplying the matrix with its transpose:\n");
    displayMatrix(result, rows, rows);  // The result is always a square matrix of size rows x rows

    // Freeing the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    for (int i = 0; i < cols; i++) {
        free(transpose[i]);
    }
    free(matrix);
    free(transpose);
    free(result);

    return 0;
}
