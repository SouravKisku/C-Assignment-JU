#include <stdio.h>
#include <stdlib.h>

// Function to calculate the average of the numbers
double calculateAverage(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

// Function to compare two numbers (for sorting)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to calculate the median of the numbers
double calculateMedian(int* arr, int n) {
    // Sort the array to find the median
    qsort(arr, n, sizeof(int), compare);

    if (n % 2 == 0) {
        // If even, median is the average of two middle elements
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        // If odd, median is the middle element
        return arr[n / 2];
    }
}

int main() {
    int n;

    // Input the number of elements in the list
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for storing the numbers
    int* arr = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the numbers
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and print the average
    double avg = calculateAverage(arr, n);
    printf("Average of the numbers: %.2f\n", avg);

    // Calculate and print the median
    double median = calculateMedian(arr, n);
    printf("Median of the numbers: %.2f\n", median);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
