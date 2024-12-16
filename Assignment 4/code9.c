#include <stdio.h>

// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function to find the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Recursive function to find the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Recursive function to find the reverse of a number
int reverse(int n, int rev) {
    if (n == 0) {
        return rev;
    }
    return reverse(n / 10, rev * 10 + n % 10);
}

// Recursive function to find the sum of the digits of a number
int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sum_of_digits(n / 10);
}

// Recursive function to find the divisors of a number
void divisors(int n, int i) {
    if (i > n) {
        return;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    divisors(n, i + 1);
}

int main() {
    int choice, num, num2;

    do {
        // Menu for different operations
        printf("\nMenu:\n");
        printf("1. Generate Fibonacci number\n");
        printf("2. Find GCD of two numbers\n");
        printf("3. Find Factorial of a number\n");
        printf("4. Find Reverse of a number\n");
        printf("5. Find Sum of the digits of a number\n");
        printf("6. Find Divisors of a number\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to find Fibonacci: ");
                scanf("%d", &num);
                printf("Fibonacci number at position %d is: %d\n", num, fibonacci(num));
                break;
            case 2:
                printf("Enter two numbers to find GCD: ");
                scanf("%d %d", &num, &num2);
                printf("GCD of %d and %d is: %d\n", num, num2, gcd(num, num2));
                break;
            case 3:
                printf("Enter a number to find factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d is: %d\n", num, factorial(num));
                break;
            case 4:
                printf("Enter a number to find its reverse: ");
                scanf("%d", &num);
                printf("Reverse of %d is: %d\n", num, reverse(num, 0));
                break;
            case 5:
                printf("Enter a number to find the sum of its digits: ");
                scanf("%d", &num);
                printf("Sum of digits of %d is: %d\n", num, sum_of_digits(num));
                break;
            case 6:
                printf("Enter a number to find its divisors: ");
                scanf("%d", &num);
                printf("Divisors of %d are: ", num);
                divisors(num, 1);
                printf("\n");
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
