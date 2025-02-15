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
    int year1, year2;

    std::cout << "Enter the first year: ";
    std::cin >> year1;

    std::cout << "Enter the second year: ";
    std::cin >> year2;

    LeapYearChecker checker1(year1);
    LeapYearChecker checker2(year2);

    return 0;
}
