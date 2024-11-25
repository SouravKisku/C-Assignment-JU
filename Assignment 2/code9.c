// W.A.P. to print all prime numbers between 1 and n. (n will be given as input).

#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // num is divisible by i, so it's not prime
        }
    }
    return 1; // num is prime
}

int main() {
    int n;

    // Input: the value of n
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are:\n", n);
    
    // Loop to check each number from 2 to n
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i); // Print the prime number
        }
    }

    printf("\n");

    return 0;
}