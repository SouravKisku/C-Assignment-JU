#include <iostream>
#include <algorithm> // for std::reverse

class NumberProcessor {
public:
    void calculate(int m, char ch) {
        if (ch == 'r') {
            // Reverse the digits of integer m
            if (numDigits(m) > 1) {
                int reversed_m = reverseDigits(m);
                std::cout << "Reversed number: " << reversed_m << std::endl;
            } else {
                std::cout << "Number should have more than one digit to reverse." << std::endl;
            }
        } else if (ch == 'p') {
            // Check if integer m is prime or not
            if (isPrime(m)) {
                std::cout << m << " is a prime number." << std::endl;
            } else {
                std::cout << m << " is not a prime number." << std::endl;
            }
        } else {
            std::cout << "Invalid character choice." << std::endl;
        }
    }

private:
    // Helper function to reverse digits of a number
    int reverseDigits(int num) {
        int reversedNum = 0;
        while (num > 0) {
            int lastDigit = num % 10;
            reversedNum = reversedNum * 10 + lastDigit;
            num /= 10;
        }
        return reversedNum;
    }

    // Helper function to check if a number is prime
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // Helper function to count the number of digits in a number
    int numDigits(int num) {
        int count = 0;
        while (num != 0) {
            num /= 10;
            count++;
        }
        return count;
    }
};

int main() {
    NumberProcessor processor;
    int num;
    char choice;

    std::cout << "Enter an integer (greater than 1 digit): ";
    std::cin >> num;
    std::cout << "Enter 'r' to reverse the digits or 'p' to check if it's prime: ";
    std::cin >> choice;

    processor.calculate(num, choice);

    return 0;
}
