// Write a program to test whether a given number is even or odd.

#include <stdio.h>

int main() {
    int num; // Number to be tested

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d is an even number.\n", num);
    } else {
        printf("%d is an odd number.\n", num);
    }

    return 0;
}