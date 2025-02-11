#include <iostream>

class LeapYearChecker {
private:
    int year;
    bool isLeap;

public:
    // Constructor
    LeapYearChecker(int y) : year(y) {
        std::cout << "Constructor called for year: " << year << std::endl;
        isLeap = checkIfLeap();
    }

    // Destructor
    ~LeapYearChecker() {
        std::cout << "Destructor called for year: " << year << std::endl;
        if (isLeap) {
            std::cout << year << " is a leap year." << std::endl;
        } else {
            std::cout << year << " is not a leap year." << std::endl;
        }
    }

private:
    bool checkIfLeap() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main() {
    LeapYearChecker year1(2024);
    LeapYearChecker year2(2023);

    return 0;
}
