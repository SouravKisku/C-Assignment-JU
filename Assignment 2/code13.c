// Consider that M is a n x n square matrix whose each row contains real numbers or 0 such that sum of each
// row is 1. If R is a n-dimensional column vector whose each component is 1/n. Use random number generator
// to create the matrix M. Write a program to compute: 𝑅 = (𝑀𝑝
// )𝑅 , where p should be taken as input.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMatrix(double M[][10], int n) {
    for (int i = 0; i < n; i++) {
        double rowSum = 0.0;
        for (int j = 0; j < n; j++) {
            M[i][j] = ((double)rand() / RAND_MAX); 
            rowSum += M[i][j];
        }
        for (int j = 0; j < n; j++) {
            M[i][j] /= rowSum;
        }
    }
}

void multiplyMatrixVector(double M[][10], double R[], double result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += M[i][j] * R[j];
        }
    }
}

void multiplyMatrices(double M1[][10], double M2[][10], double result[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

void matrixPower(double M[][10], double result[][10], int n, int p) {
    double temp[10][10];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) result[i][j] = 1;
            else result[i][j] = 0;
        }
    }

    for (int power = 1; power <= p; power++) {
        multiplyMatrices(result, M, temp, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    int n, p;
    
    srand(time(NULL));
    
    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);
    printf("Enter the value of p: ");
    scanf("%d", &p);

    double M[10][10], Mp[10][10], R[10], result[10];

    generateMatrix(M, n);

    for (int i = 0; i < n; i++) {
        R[i] = 1.0 / n;
    }

    matrixPower(M, Mp, n, p);

    multiplyMatrixVector(Mp, R, result, n);

    printf("The resulting vector R after computing M^p * R is:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}
