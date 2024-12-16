// WAP to swap odd positioned nos with even positioned nos in an array

#include <stdio.h>

void swapOddEvenPositions(int arr[], int n) {
    for (int i = 0; i < n - 1; i += 2) {
        // Swap the odd and even positions
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
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

    // Swap odd and even positioned elements
    swapOddEvenPositions(arr, n);

    // Print the modified array
    printf("Array after swapping odd and even positions: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
