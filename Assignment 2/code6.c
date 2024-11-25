// Write a program to compute GCD of two number. Implement the program using the Euclid Algorithm and the factorization method.

#include <stdio.h>

int gcdEuclid(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcdFactorization(int a, int b) {
    int gcd = 1;
    int i;
    
    for (i = 2; i <= a && i <= b; i++) {
        while (a % i == 0 && b % i == 0) {
            gcd *= i;
            a /= i;
            b /= i;
        }
    }
    return gcd;
}

int main() {
    int a, b;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("GCD of %d and %d using Euclid's Algorithm is: %d\n", a, b, gcdEuclid(a, b));
    
    printf("GCD of %d and %d using Factorization Method is: %d\n", a, b, gcdFactorization(a, b));
    
    return 0;
}
