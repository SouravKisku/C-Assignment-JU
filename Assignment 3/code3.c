//WAp to find mean, median and standard deviation of a list of numbers

#include <stdio.h>
#include <math.h>

void calculateMean(int arr[], int n, double *mean) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    *mean = (double)sum / n;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void calculateMedian(int arr[], int n, double *median) {
    sortArray(arr, n);
    if (n % 2 == 0) {
        *median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        *median = arr[n / 2];
    }
}

void calculateStandardDeviation(int arr[], int n, double mean, double *stdDev) {
    double sumSqDiff = 0.0;
    for (int i = 0; i < n; i++) {
        sumSqDiff += (arr[i] - mean) * (arr[i] - mean);
    }
    *stdDev = sqrt(sumSqDiff / n);
}

int main() {
    int n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];

    // Input the array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    double mean, median, stdDev;

    // Calculate mean
    calculateMean(arr, n, &mean);

    // Calculate median
    calculateMedian(arr, n, &median);

    // Calculate standard deviation
    calculateStandardDeviation(arr, n, mean, &stdDev);

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Standard Deviation: %.2f\n", stdDev);

    return 0;
}
