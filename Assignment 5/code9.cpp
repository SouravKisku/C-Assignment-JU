#include <iostream>

class SquareCalculator {
public:
    inline int square(int x) {
        return x * x;
    }
};

int main() {
    SquareCalculator calculator;
    int num = 5;
    int sq = calculator.square(num);
    std::cout << "Square of " << num << " is " << sq << std::endl;
    return 0;
}
