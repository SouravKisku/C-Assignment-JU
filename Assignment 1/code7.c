// Write a program to swap the values of two variables
// (i) Case 1:-- using third variable
// (ii) Case 2:-- without using any third variable

#include <stdio.h>

int main() {
    int a, b, temp, choice;

    printf("Enter two numbers (a and b): ");
    scanf("%d %d", &a, &b);

    printf("\nChoose swapping method:\n");
    printf("1. Swap using third variable\n");
    printf("2. Swap without using third variable\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            temp = a;
            a = b;
            b = temp;
            printf("\nAfter swapping (using third variable): a = %d, b = %d\n", a, b);
            break;

        case 2: 
            a = a + b;
            b = a - b;
            a = a - b;
            printf("\nAfter swapping (without third variable): a = %d, b = %d\n", a, b);
            break;

        default: 
            printf("\nInvalid choice! Please select either 1 or 2.\n");
    }

    return 0;
}

