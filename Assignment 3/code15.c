// WAP to generate the  Pascal’s triangle :-- 
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1…..upto 10 lines


#include <stdio.h>

// Function to generate and print Pascal's Triangle
void generatePascalsTriangle(int n) {
    int arr[n][n];  // Declare a 2D array to store the values of Pascal's Triangle

    // Loop through each row
    for (int i = 0; i < n; i++) {
        // Set the first and last element of each row to 1
        arr[i][0] = arr[i][i] = 1;
        
        // Fill the other elements of the row
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    // Print the Pascal's Triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 10;  // Number of lines to print
    generatePascalsTriangle(n);  // Generate and print the Pascal's Triangle

    return 0;
}
