#include <stdio.h>
#include <stdlib.h>

// Function to compare for descending order (used by qsort)
int compareDescending(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Function to compare for ascending order (used by qsort)
int compareAscending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to split the array into two parts and sort them
void sortArrayParts(int arr[], int size, int splitIndex) {
    // Sort the first part in descending order
    qsort(arr, splitIndex, sizeof(int), compareDescending);

    // Sort the second part in ascending order
    qsort(arr + splitIndex, size - splitIndex, sizeof(int), compareAscending);
}

int main() {
    int arr[] = {9, 7, 5, 6, 2, 8, 1, 4, 3, 0};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);
    int splitIndex = size / 2;  // You can change this index to split at a different point

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the function to sort the first and second parts
    sortArrayParts(arr, size, splitIndex);

    // Print the final array after sorting
    printf("Final array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
