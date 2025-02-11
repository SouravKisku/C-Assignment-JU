#include <iostream>

class Complex {
private:
    int real;
    int imaginary;

public:
    Complex(int r = 0, int i = 0) : real(r), imaginary(i) {}

    void display() const {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }

    // Friend function to add two complex numbers
    friend Complex addComplex(const Complex& c1, const Complex& c2);
};

Complex addComplex(const Complex& c1, const Complex& c2) {
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;
    return sum;
}

int main() {
    Complex c1(3, 4);
    Complex c2(5, -2);

    std::cout << "Complex number 1: ";
    c1.display();

    std::cout << "Complex number 2: ";
    c2.display();

    Complex sum = addComplex(c1, c2);

    std::cout << "Sum: ";
    sum.display();

    return 0;
}
