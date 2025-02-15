#include <iostream>
using namespace std;

class Circle {
protected:
    double radius; // Protected member

public:
    void setRadius(double r) { // Public method to set radius
        radius = r;
    }

    double getRadius() { // Public method to get radius
        return radius;
    }
};

class Area : public Circle {
public:
    double calculateArea() { // Public method to calculate area
        return 3.14159 * radius * radius;
    }
};

int main() {
    Area circle;
    double r;
    
    cout << "Enter the radius of the circle: ";
    cin >> r;
    
    circle.setRadius(r); // Setting radius using public function
    
    cout << "The area of the circle is: " << circle.calculateArea() << endl;
    
    return 0;
}