// Write a program to convert any centigrade temperature value to farenheit and vice versa.

#include <stdio.h>

int main() {
    float temperature, converted_temperature;
    int choice;

    // Display menu for conversion options
    printf("Choose the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Convert based on user choice
    if (choice == 1) {
        // Celsius to Fahrenheit
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        converted_temperature = (temperature * 9 / 5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, converted_temperature);
    } else if (choice == 2) {
        // Fahrenheit to Celsius
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        converted_temperature = (temperature - 32) * 5 / 9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, converted_temperature);
    } else {
        printf("Invalid choice! Please choose 1 or 2.\n");
    }

    return 0;
}
