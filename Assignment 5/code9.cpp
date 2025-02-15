#include <iostream>

class SquareCalculator {
public:
    inline int square(int x) {
        return x * x;
    }
};

int main() {
    SquareCalculator calculator;
    int num;

    std::cout << "Enter a number to calculate its square: ";
    std::cin >> num;

    int sq = calculator.square(num);
    std::cout << "Square of " << num << " is " << sq << std::endl;
    return 0;
}
