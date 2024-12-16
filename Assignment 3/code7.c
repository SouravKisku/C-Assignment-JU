// WAP to insert an element in the array such that the resultant array remain sorted,

#include <stdio.h>

void insertElement(int arr[], int *n, int element) {
    int i;

    // Find the position to insert the element
    for (i = *n - 1; (i >= 0 && arr[i] > element); i--) {
        arr[i + 1] = arr[i]; // Shift elements to the right
    }

    // Insert the element at the correct position
    arr[i + 1] = element;
    (*n)++;
}

int main() {
    int n, element;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n + 1]; // Extra space for the new element

    // Input the sorted array elements
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to be inserted
    printf("Enter the element to insert: ");
    scanf("%d", &element);

    // Insert the element while maintaining sorted order
    insertElement(arr, &n, element);

    // Print the resultant array
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
