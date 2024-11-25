// Write a program to take a three digit number from the user to test whether the sum of the first & last digits is equal to the twice of the middle element /digit.

#include <stdio.h>

int main() {
    int num, first_digit, middle_digit, last_digit, sum_first_last;

    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    first_digit = num / 100;  
    middle_digit = (num / 10) % 10;  
    last_digit = num % 10;  
    sum_first_last = first_digit + last_digit;

    if (sum_first_last == 2 * middle_digit) {
        printf("The sum of the first and last digits is equal to twice the middle digit.\n");
    } else {
        printf("The sum of the first and last digits is NOT equal to twice the middle digit.\n");
    }

    return 0;
}
