// Write a program to compute GCD of two number. Implement the program using the Euclid Algorithm and the factorization method.

#include <stdio.h>

// Function to compute GCD using Euclid's Algorithm
int gcdEuclid(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the GCD using Prime Factorization
int gcdFactorization(int a, int b) {
    int gcd = 1;

    // Iterate through possible factors
    for (int i = 2; i <= (a < b ? a : b); i++) {
        while (a % i == 0 && b % i == 0) {
            gcd *= i;
            a /= i;
            b /= i;
        }
    }
    return gcd;
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // Compute GCD using Euclid's Algorithm
    int gcd1 = gcdEuclid(num1, num2);
    printf("GCD (Euclid's Algorithm): %d\n", gcd1);

    // Compute GCD using Prime Factorization
    int gcd2 = gcdFactorization(num1, num2);
    printf("GCD (Prime Factorization): %d\n", gcd2);

    return 0;
}
