#include <iostream>

class Pattern {
public:
    int rows;

    Pattern(int r) : rows(r) {}

    void printPattern() {
        for (int i = 1; i <= rows; ++i) {
            // Print spaces
            for (int j = 1; j <= rows - i; ++j) {
                std::cout << "  "; // Two spaces for alignment
            }

            // Print increasing numbers
            for (int j = 1; j <= i; ++j) {
                std::cout << j << " ";
            }

            // Print decreasing numbers
            for (int j = i - 1; j >= 1; --j) {
                std::cout << j << " ";
            }

            std::cout << std::endl;
        }
    }
};

int main() {
    Pattern myPattern(5); // You can change the number of rows here
    myPattern.printPattern();

    return 0;
}
