// Write a program to Calculate simple interest given principal (p), rate of interest per annum (r), number of years(n) and consider all the relevant cases.


#include <stdio.h>

int main() {
    float principal, rate, years, simple_interest;

    // User input
    printf("Enter the Principal amount (P): ");
    scanf("%f", &principal);

    if (principal <= 0) {
        printf("Principal amount should be greater than 0.\n");
        return 1; 
    }

    printf("Enter the Rate of Interest per annum (R): ");
    scanf("%f", &rate);

    if (rate <= 0 || rate > 100) {
        printf("Rate of interest should be between 0 and 100.\n");
        return 1;
    }

    printf("Enter the Number of Years (N): ");
    scanf("%f", &years);

    if (years <= 0) {
        printf("Number of years should be greater than 0.\n");
        return 1; 
    }

    simple_interest = (principal * rate * years) / 100;

    printf("\nSimple Interest Calculation:\n");
    printf("Principal: %.2f\n", principal);
    printf("Rate of Interest: %.2f%%\n", rate);
    printf("Number of Years: %.2f\n", years);
    printf("Simple Interest: %.2f\n", simple_interest);

    return 0;
}
