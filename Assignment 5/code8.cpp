#include <iostream>

class Base {
public:
    int data;

    // Default constructor
    Base() : data(0) {
        std::cout << "Base Default Constructor" << std::endl;
    }

    // Parameterized constructor
    Base(int d) : data(d) {
        std::cout << "Base Parameterized Constructor: " << data << std::endl;
    }

    // Copy constructor
    Base(const Base& other) : data(other.data) {
        std::cout << "Base Copy Constructor: " << data << std::endl;
    }

    // Virtual destructor
    virtual ~Base() {
        std::cout << "Base Virtual Destructor" << std::endl;
    }

    virtual void display() {
        std::cout << "Base class, data = " << data << std::endl;
    }
};

class Derived : public Base {
public:
    int extraData;

    // Default constructor
    Derived() : extraData(0) {
        std::cout << "Derived Default Constructor" << std::endl;
    }

    // Parameterized constructor
    Derived(int d, int e) : Base(d), extraData(e) {
        std::cout << "Derived Parameterized Constructor: data = " << data << ", extraData = " << extraData << std::endl;
    }

    // Copy constructor
    Derived(const Derived& other) : Base(other), extraData(other.extraData) {
        std::cout << "Derived Copy Constructor: data = " << data << ", extraData = " << extraData << std::endl;
    }

    // Destructor
    ~Derived() override {
        std::cout << "Derived Destructor" << std::endl;
    }

    void display() override {
        std::cout << "Derived class, data = " << data << ", extraData = " << extraData << std::endl;
    }
};

int main() {
    std::cout << "Copy Constructor Demo:" << std::endl;
    Base b1(10);  // We need this to create b2
    Derived d1(20, 30);  // We need this to create d2
    Base b2 = b1;
    Derived d2 = d1;
    std::cout << std::endl;

    std::cout << "Parameterized Constructor Demo:" << std::endl;
    Base b3(15);
    Derived d3(25, 35);
    std::cout << std::endl;

    std::cout << "Virtual Destructor Demo:" << std::endl;
    Base* poly = new Derived(40, 50);
    poly->display();
    delete poly;

    return 0;`
}

