#include <iostream>

class Circle {
private:
    double radius;

    class AreaCalculator {
    public:
        double calculateArea(double radius) {
            return 3.14159 * radius * radius;
        }
    };

public:
    Circle(double r) : radius(r) {}

    void displayArea() {
        AreaCalculator calculator;
        std::cout << "Area of the circle: " << calculator.calculateArea(radius) << std::endl;
    }
};

int main() {
    double userRadius;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> userRadius;

    Circle myCircle(userRadius);
    myCircle.displayArea();

    return 0;
}
