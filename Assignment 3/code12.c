// WAP to multiply two n x n matrices.

#include <stdio.h>

void inputMatrix(int n, int matrix[n][n]) {
    printf("Enter the elements of the %dx%d matrix (row by row):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplyMatrices(int n, int mat1[n][n], int mat2[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input the dimension of the matrix
    printf("Enter the dimension (n) of the n x n matrices: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0) {
        printf("Invalid dimension. Please enter a positive integer.\n");
        return 1;
    }

    int mat1[n][n], mat2[n][n], result[n][n];

    // Input the first matrix
    printf("Enter the elements of the first matrix:\n");
    inputMatrix(n, mat1);

    // Input the second matrix
    printf("Enter the elements of the second matrix:\n");
    inputMatrix(n, mat2);

    // Multiply the matrices
    multiplyMatrices(n, mat1, mat2, result);

    // Print the result
    printf("The product of the matrices is:\n");
    printMatrix(n, result);

    return 0;
}
