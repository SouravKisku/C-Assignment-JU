// Write a program to generate the n-th Fibonacci number where n will be taken as input. There is a formula
// for computing the n-th Fibonacci number:
// 𝐹𝑛 =  1/root5(1+root5/2)^n - 1/root5(1-root5/2)^n

// Compute n-th Fibonacci number without using the formula and using the formula, and compare these two. Are
// they same?

#include <stdio.h>
#include <math.h>

long long fibonacciIterative(int n) {
    if (n <= 1) {
        return n;
    }
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

double fibonacciFormula(int n) {
    double phi = (1 + sqrt(5)) / 2;  
    double psi = (1 - sqrt(5)) / 2;  
    return (pow(phi, n) - pow(psi, n)) / sqrt(5);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    long long fibIterative = fibonacciIterative(n);
    printf("Fibonacci number using iterative method: %lld\n", fibIterative);

    double fibFormula = fibonacciFormula(n);
    printf("Fibonacci number using Binet's formula: %.0f\n", fibFormula);

    if ((long long)fibFormula == fibIterative) {
        printf("Both methods give the same result.\n");
    } else {
        printf("The results are different due to precision issues in Binet's formula.\n");
    }

    return 0;
}