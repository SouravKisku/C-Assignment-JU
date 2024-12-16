#include <stdio.h>

// Function to convert a decimal number to any given base
void decimalToBase(int num, int base) {
    // Array to store the digits for base 16 (Hexadecimal)
    char digits[] = "0123456789ABCDEF";

    // If the number is zero, print 0 directly
    if (num == 0) {
        printf("0");
        return;
    }

    // Create an array to store the result (the number in the given base)
    char result[32];
    int index = 0;

    // Process the number by repeatedly dividing by the base
    while (num > 0) {
        result[index++] = digits[num % base];  // Store the remainder (digit in the new base)
        num = num / base;  // Update the number by dividing by the base
    }

    // Print the result in reverse order as we collected the digits in reverse
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
}

int main() {
    int num, base;

    // Input the decimal number and the base to convert to
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Enter the base (between 2 and 16): ");
    scanf("%d", &base);

    // Check if the base is valid
    if (base < 2 || base > 16) {
        printf("Invalid base. Please enter a base between 2 and 16.\n");
    } else {
        printf("The number %d in base %d is: ", num, base);
        decimalToBase(num, base);
        printf("\n");
    }

    return 0;
}
