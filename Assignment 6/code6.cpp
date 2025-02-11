#include <iostream>

class Calculator {
public:
    class Addition {
    public:
        double add(double a, double b) {
            return a + b;
        }
    };

    class Subtraction {
    public:
        double subtract(double a, double b) {
            return a - b;
        }
    };

    class Multiplication {
    public:
        double multiply(double a, double b) {
            return a * b;
        }
    };

    class Division {
    public:
        double divide(double a, double b) {
            if (b == 0) {
                std::cout << "Error: Division by zero!" << std::endl;
                return 0;
            }
            return a / b;
        }
    };
};

int main() {
    Calculator::Addition addition;
    Calculator::Subtraction subtraction;
    Calculator::Multiplication multiplication;
    Calculator::Division division;

    double num1, num2;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
        }

        switch (choice) {
            case 1:
                std::cout << "Result: " << addition.add(num1, num2) << std::endl;
                break;
            case 2:
                std::cout << "Result: " << subtraction.subtract(num1, num2) << std::endl;
                break;
            case 3:
                std::cout << "Result: " << multiplication.multiply(num1, num2) << std::endl;
                break;
            case 4:
                std::cout << "Result: " << division.divide(num1, num2) << std::endl;
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
