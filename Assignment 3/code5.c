// WAP to search an element in the array. If it is  found, print index else print "number is not found".

#include <stdio.h>

int searchElement(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int n, target;

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

    // Ask the user for the target element to search
    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Search for the element in the array
    int index = searchElement(arr, n, target);

    // Print the result
    if (index != -1) {
        printf("Number found at index %d\n", index);
    } else {
        printf("Number is not found\n");
    }

    return 0;
}
