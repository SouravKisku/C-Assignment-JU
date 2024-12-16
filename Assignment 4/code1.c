#include <stdio.h>

void findElements(int arr[], int size) {
    int thirdMax = -2147483648, fifthMin = 2147483647, middle = arr[size / 2];
    int firstMin = 2147483647, secondMin = 2147483647;
    int firstMax = -2147483648, secondMax = -2147483648, thirdMaxTemp = -2147483648;

    // Find third maximum, fifth minimum and middle element
    for (int i = 0; i < size; i++) {
        // Find maximum values
        if (arr[i] > firstMax) {
            thirdMaxTemp = secondMax;
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax) {
            thirdMaxTemp = secondMax;
            secondMax = arr[i];
        } else if (arr[i] > thirdMaxTemp) {
            thirdMaxTemp = arr[i];
        }

        // Find minimum values
        if (arr[i] < firstMin) {
            secondMin = firstMin;
            firstMin = arr[i];
        } else if (arr[i] < secondMin) {
            secondMin = arr[i];
        }

    }

    thirdMax = thirdMaxTemp;

    // Printing the results
    printf("Third Maximum: %d\n", thirdMax);
    printf("Fifth Minimum: %d\n", secondMin);
    printf("Middle Element: %d\n", middle);
}

int main() {
    int arr[10];

    // Input 10 elements into the array
    printf("Enter 10 elements: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to find third maximum, fifth minimum, and middle element
    findElements(arr, 10);

    return 0;
}
