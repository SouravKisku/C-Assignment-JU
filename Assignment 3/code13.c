//WAP to take two 2-D arrays then sort those two arrays, finally store the sum of them into a third array that will also be sorted.

#include <stdio.h>
#include <stdlib.h>

// Function to compare two elements for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to sort a 2D array
void sort2DArray(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        qsort(arr[i], cols, sizeof(int), compare);
    }
}

// Function to display a 2D array
void display2DArray(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr1[2][3], arr2[2][3], arr3[2][3];
    int rows = 2, cols = 3;

    // Taking input for the first 2D array
    printf("Enter elements of the first 2D array (2x3):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    // Taking input for the second 2D array
    printf("Enter elements of the second 2D array (2x3):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Sorting both 2D arrays
    sort2DArray(arr1, rows, cols);
    sort2DArray(arr2, rows, cols);

    // Storing the sum of the arrays into the third array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    // Sorting the third array
    sort2DArray(arr3, rows, cols);

    // Displaying the arrays
    printf("\nSorted first 2D array:\n");
    display2DArray(arr1, rows, cols);

    printf("\nSorted second 2D array:\n");
    display2DArray(arr2, rows, cols);

    printf("\nSum of the arrays (sorted):\n");
    display2DArray(arr3, rows, cols);

    return 0;
}
