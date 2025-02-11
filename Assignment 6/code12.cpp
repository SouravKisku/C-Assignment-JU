#include <iostream>

class Shape {
public:
    virtual void display() {
        std::cout << "This is a shape" << std::endl;
    }
    virtual ~Shape() {}
};

class Polygon : public Shape {
public:
    void display() override {
        std::cout << "Polygon is a shape" << std::endl;
    }
    virtual ~Polygon(){}
};

class Rectangle : public Polygon {
public:
    void display() override {
        std::cout << "Rectangle is a polygon" << std::endl;
    }
    virtual ~Rectangle() {}
};

class Triangle : public Polygon {
public:
    void display() override {
        std::cout << "Triangle is a polygon" << std::endl;
    }
    virtual ~Triangle(){}
};

class Square : public Rectangle {
public:
    void display() override {
        std::cout << "Square is a rectangle" << std::endl;
    }
    virtual ~Square(){}
};

int main() {
    Shape* shape = new Shape();
    Polygon* polygon = new Polygon();
    Rectangle* rectangle = new Rectangle();
    Triangle* triangle = new Triangle();
    Square* square = new Square();

    std::cout << "Shape object: ";
    shape->display();

    std::cout << "Polygon object: ";
    polygon->display();

    std::cout << "Rectangle object: ";
    rectangle->display();

    std::cout << "Triangle object: ";
    triangle->display();

    std::cout << "Square object: ";
    square->display();
      delete shape;
    delete polygon;
    delete rectangle;
    delete triangle;
    delete square;

    return 0;
}
