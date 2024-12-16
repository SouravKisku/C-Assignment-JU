// WAP to take one 2-D array, find the transpose of  it, finally print the multiplied value of the matrix with its transpose.

#include <stdio.h>

void multiplyMatrices(int mat1[][10], int mat2[][10], int res[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            res[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                res[i][j] += mat1[i][k] * mat2[j][k];
            }
        }
    }
}

void findTranspose(int mat[][10], int trans[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }
}

int main() {
    int rows, cols;
    int mat[10][10], trans[10][10], result[10][10];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Find the transpose
    findTranspose(mat, trans, rows, cols);

    // Multiply the matrix with its transpose
    multiplyMatrices(mat, trans, result, rows, cols);

    // Print the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // Print the transpose of the matrix
    printf("\nTranspose of the Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

    // Print the result of the multiplication
    printf("\nResult of Matrix multiplied by its Transpose:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}