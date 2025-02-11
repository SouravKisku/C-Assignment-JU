#include <iostream>
#include <cmath>  // Required for sqrt()

class Triangle {
private:
    double side1, side2, side3;
    double area, perimeter;

    // Function defined inside the class
    double calculateArea() {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2;
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
        return area;
    }

public:
    // Function defined inside the class
    void takeInput() {
        std::cout << "Enter the lengths of the three sides of the triangle: ";
        std::cin >> side1 >> side2 >> side3;
    }

    // Function defined outside the class
    void calculatePerimeter();

    // Function defined outside the class
    void printData();
};

void Triangle::calculatePerimeter() {
    perimeter = side1 + side2 + side3;
}

void Triangle::printData() {
    std::cout << "Area of the triangle: " << calculateArea() << std::endl;
    std::cout << "Perimeter of the triangle: " << perimeter << std::endl;
}

int main() {
    Triangle myTriangle;
    myTriangle.takeInput();
    myTriangle.calculatePerimeter();
    myTriangle.printData();

    return 0;
}
