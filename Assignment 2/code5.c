// Write a program to find the value of one number raised to the power of the another number without using the library function pow()


#include <stdio.h>

int main() {
    int base, exponent;
    long long result = 1;  

    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    if (exponent < 0) {
        printf("Exponent should be a non-negative integer.\n");
        return 0;  
    }

    for (int i = 1; i <= exponent; i++) {
        result *= base;  
    }

    printf("%d raised to the power of %d is: %lld\n", base, exponent, result);

    return 0;
}
