// . Write a program to convert any centigrade temperature value to Fahrenheit and vice-versa. Write a menu driven program.

#include <stdio.h>
 
void celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
}

void fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
}

int main() {
    int choice;
    float temperature;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Celsius to Fahrenheit
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                celsiusToFahrenheit(temperature);
                break;
            case 2:
                // Fahrenheit to Celsius
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                fahrenheitToCelsius(temperature);
                break;
            case 3:
                // Exit
                printf("Exiting the program.\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }

    } while (choice != 3);  // Continue until user chooses to exit

    return 0;
}
