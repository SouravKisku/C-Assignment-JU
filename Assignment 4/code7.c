#include <stdio.h>
#include <stdlib.h>

void sort_array(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }
}

void sum_and_sort_arrays(int arr1[][3], int arr2[][3], int result[][3], int rows, int cols) {
    // Sort both input arrays
    sort_array(arr1, rows, cols);
    sort_array(arr2, rows, cols);

    // Calculate the sum of corresponding elements and store in the result array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    // Sort the result array
    sort_array(result, rows, cols);
}

int main() {
    int arr1[3][3] = {{3, 1, 4}, {2, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int result[3][3];

    sum_and_sort_arrays(arr1, arr2, result, 3, 3);

    printf("Sorted sum array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}