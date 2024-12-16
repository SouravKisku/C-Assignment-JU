// WAP to find transpose of matrix

#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix (row by row):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Input the dimensions of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Validate input
    if (rows <= 0 || cols <= 0) {
        printf("Invalid dimensions. Please enter positive integers.\n");
        return 1;
    }

    int matrix[rows][cols];
    int transpose[cols][rows];

    // Input the matrix elements
    inputMatrix(rows, cols, matrix);

    // Compute the transpose of the matrix
    transposeMatrix(rows, cols, matrix, transpose);

    // Print the transpose
    printf("The transpose of the matrix is:\n");
    printMatrix(cols, rows, transpose);

    return 0;
}
