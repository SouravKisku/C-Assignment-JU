#include <iostream>

class Circle {
private:
    double radius;
    double area;

protected:
    double getRadius() const { // Protected function to allow derived classes to access radius
        return radius;
    }

public:
    Circle(double r) : radius(r), area(0.0) {}

    void calculateArea() {
        area = 3.14159 * radius * radius;
    }

    void displayArea() const {
        std::cout << "Area of the circle: " << area << std::endl;
    }

    // Function to set radius with validation
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        } else {
            std::cout << "Invalid radius. Radius must be positive." << std::endl;
        }
    }
};

int main() {
    Circle myCircle(5.0);
    myCircle.calculateArea();
    myCircle.displayArea(); // Output: Area of the circle: 78.5397

    // Example of using setRadius to modify the radius
    myCircle.setRadius(7.0);
    myCircle.calculateArea();
    myCircle.displayArea(); // Output: Area of the circle: 153.937

    return 0;
}
