#include <iostream>
#include <string>
#include <cmath>

class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& n) : name(n) {}

    virtual double area() const = 0; // Pure virtual function

    virtual void display() const {
        std::cout << "Shape: " << name << std::endl;
    }

    virtual ~Shape() {
        std::cout << "Virtual destructor called for Shape: " << name << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        Shape::display();
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }

     ~Circle() override {
        std::cout << "Destructor called for Circle" << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    void display() const override {
        Shape::display();
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
    ~Rectangle() override {
        std::cout << "Destructor called for Rectangle" << std::endl;
    }
};

class Trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;

public:
    Trapezoid(double b1, double b2, double h) : Shape("Trapezoid"), base1(b1), base2(b2), height(h) {}

    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }

    void display() const override {
        Shape::display();
        std::cout << "Base 1: " << base1 << ", Base 2: " << base2 << ", Height: " << height << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
    ~Trapezoid() override {
        std::cout << "Destructor called for Trapezoid" << std::endl;
    }
};

int main() {
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);
    Shape* trapezoid = new Trapezoid(3.0, 5.0, 4.0);

    std::cout << "Circle:\n";
    circle->display();

    std::cout << "\nRectangle:\n";
    rectangle->display();

    std::cout << "\nTrapezoid:\n";
    trapezoid->display();

    delete circle;
    delete rectangle;
    delete trapezoid;

    return 0;
}
