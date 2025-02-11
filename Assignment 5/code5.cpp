#include <iostream>

class Complex {
private:
    int real;
    int imaginary;

public:
    // Constructor with no arguments
    Complex() : real(0), imaginary(0) {}

    // Constructor with one argument
    Complex(int r) : real(r), imaginary(0) {}

    // Constructor with two arguments
    Complex(int r, int i) : real(r), imaginary(i) {}

    // Function to display the complex number
    void show() const {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }

    // Function to add two complex numbers
    Complex sum(const Complex& other) const {
        int newReal = real + other.real;
        int newImaginary = imaginary + other.imaginary;
        return Complex(newReal, newImaginary);
    }
};

int main() {
    Complex c1;          // Uses constructor with no arguments
    Complex c2(5);       // Uses constructor with one argument
    Complex c3(3, 4);    // Uses constructor with two arguments

    std::cout << "c1: ";
    c1.show(); // Output: 0 + 0i

    std::cout << "c2: ";
    c2.show(); // Output: 5 + 0i

    std::cout << "c3: ";
    c3.show(); // Output: 3 + 4i

    Complex c4 = c3.sum(c2);
    std::cout << "c3 + c2: ";
    c4.show(); // Output: 8 + 4i

    return 0;
}
