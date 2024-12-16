#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum size for the arrays

// Function to read a matrix
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to sort the matrix in ascending order (by converting it to a 1-D array)
void sortMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int temp[MAX * MAX];
    int k = 0;

    // Flatten the matrix into a 1-D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[k++] = matrix[i][j];
        }
    }

    // Sort the 1-D array
    qsort(temp, k, sizeof(int), (int (*)(const void *, const void *))compare);

    // Refill the matrix with sorted values
    k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = temp[k++];
        }
    }
}

// Comparison function for qsort (ascending order)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to sum two matrices and store the result in a third matrix
void sumMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];

    // Read the matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Read the two matrices
    printf("Enter the elements for the first matrix:\n");
    readMatrix(matrix1, rows, cols);

    printf("Enter the elements for the second matrix:\n");
    readMatrix(matrix2, rows, cols);

    // Sort both matrices
    sortMatrix(matrix1, rows, cols);
    sortMatrix(matrix2, rows, cols);

    // Sum the matrices
    sumMatrices(matrix1, matrix2, result, rows, cols);

    // Sort the result matrix
    sortMatrix(result, rows, cols);

    // Print the final sorted matrix
    printf("The final sorted matrix after summing the matrices is:\n");
    printMatrix(result, rows, cols);

    return 0;
}
