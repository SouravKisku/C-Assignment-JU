// . Write a program to compute following series
// A. 1/1!+2/2!+3/3!+…..upto 10 terms.
// B. Sine(x)
// C. Cos(x)
// D. Log(1+x)

#include <stdio.h>
#include <math.h> // Include math.h for pow()

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// A. Series: 1/1! + 2/2! + 3/3! + ... (up to 10 terms)
double seriesA() {
    double sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += (double)i / factorial(i);
    }
    return sum;
}

// B. Sine(x) series: x - x^3/3! + x^5/5! - x^7/7! + ...
double sineSeries(double x) {
    double sum = 0;
    int sign = 1; // Alternating sign
    for (int i = 1; i <= 19; i += 2) { // Extend series for better accuracy
        sum += sign * (pow(x, i) / factorial(i));
        sign = -sign; // Alternate sign
    }
    return sum;
}

// C. Cosine(x) series: 1 - x^2/2! + x^4/4! - x^6/6! + ...
double cosineSeries(double x) {
    double sum = 1; // Start with 1 (cosine at 0)
    int sign = -1;  // Alternating sign
    for (int i = 2; i <= 20; i += 2) { // Extend series for better accuracy
        sum += sign * (pow(x, i) / factorial(i));
        sign = -sign; // Alternate sign
    }
    return sum;
}

// D. Log(1 + x) series: x - x^2/2 + x^3/3 - x^4/4 + ...
double logSeries(double x) {
    if (x <= -1) {
        printf("Log(1 + x) is undefined for x <= -1.\n");
        return 0;
    }
    double sum = 0;
    int sign = 1;
    for (int i = 1; i <= 20; i++) { // Extend series for better accuracy
        sum += sign * (pow(x, i) / i);
        sign = -sign;
    }
    return sum;
}

int main() {
    // A. Compute the series 1/1! + 2/2! + 3/3! + ... up to 10 terms
    printf("Series A (1/1! + 2/2! + 3/3! + ...): %.6f\n", seriesA());

    // B. Sine(x) for x
    double x;
    printf("Enter the value of x for sine series: ");
    scanf("%lf", &x);
    printf("Sine(x) using series: %.6f\n", sineSeries(x));

    // C. Cosine(x) for x
    printf("Enter the value of x for cosine series: ");
    scanf("%lf", &x);
    printf("Cosine(x) using series: %.6f\n", cosineSeries(x));

    // D. Log(1 + x) for x
    double y;
    printf("Enter the value of x for log(1 + x) series: ");
    scanf("%lf", &y);
    printf("Log(1 + x) using series: %.6f\n", logSeries(y));

    return 0;
}
