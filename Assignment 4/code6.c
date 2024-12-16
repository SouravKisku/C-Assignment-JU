#include <stdio.h>
#include <stdbool.h>

#define MAX 10  // Maximum size of the matrix

// Function to read a matrix
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return;
    }
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to check if a matrix is symmetric
bool isSymmetric(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    if (rows != cols) {
        return false;  // A symmetric matrix must be square
    }

    // Transpose the matrix
    transposeMatrix(matrix, transpose, rows, cols);

    // Check if matrix is equal to its transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != transpose[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int matrix[MAX][MAX], transpose[MAX][MAX], result[MAX][MAX];
    int rows, cols;

    // Read the matrix dimensions
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Read the matrix elements
    readMatrix(matrix, rows, cols);

    // Check if the matrix is symmetric
    if (isSymmetric(matrix, transpose, rows, cols)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}
