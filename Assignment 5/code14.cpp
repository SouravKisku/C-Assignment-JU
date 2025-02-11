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
    NumberSwapper swapper(5, 10);

    std::cout << "Before swapping: ";
    swapper.display();

    swapNumbers(swapper);

    std::cout << "After swapping: ";
    swapper.display();

    return 0;
}
