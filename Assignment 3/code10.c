// WAP to find norm of matrix

#include <stdio.h>
#include <math.h>

void inputMatrix(int rows, int cols, double matrix[rows][cols]) {
    printf("Enter the elements of the matrix (row by row):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

double calculateFrobeniusNorm(int rows, int cols, double matrix[rows][cols]) {
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j] * matrix[i][j];
        }
    }
    return sqrt(sum);
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

    double matrix[rows][cols];

    // Input the matrix elements
    inputMatrix(rows, cols, matrix);

    // Calculate the Frobenius norm
    double norm = calculateFrobeniusNorm(rows, cols, matrix);

    // Print the result
    printf("The Frobenius norm of the matrix is: %.2f\n", norm);

    return 0;
}
