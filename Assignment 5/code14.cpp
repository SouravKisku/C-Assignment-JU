#include <iostream>

class NumberSwapper {
private:
    int num1;
    int num2;

public:
    NumberSwapper(int n1, int n2) : num1(n1), num2(n2) {}

    void display() const {
        std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    }

    // Friend function to swap numbers
    friend void swapNumbers(NumberSwapper& obj);
};

void swapNumbers(NumberSwapper& obj) {
    obj.num1 = obj.num1 + obj.num2;
    obj.num2 = obj.num1 - obj.num2;
    obj.num1 = obj.num1 - obj.num2;
}

int main() {
    int input1, input2;

    std::cout << "Enter the first number: ";
    std::cin >> input1;

    std::cout << "Enter the second number: ";
    std::cin >> input2;

    NumberSwapper swapper(input1, input2);

    std::cout << "Before swapping: ";
    swapper.display();

    swapNumbers(swapper);

    std::cout << "After swapping: ";
    swapper.display();

    return 0;
}
