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
    Circle myCircle(5.0);
    myCircle.displayArea(); // Output: Area of the circle: 78.5397
    return 0;
}
