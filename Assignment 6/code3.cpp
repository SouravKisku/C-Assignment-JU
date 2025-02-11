#include <iostream>

class Rectangle {
private:
    double length;
    double breadth;

public:
    void getData() {
        std::cout << "Enter length: ";
        std::cin >> length;
        std::cout << "Enter breadth: ";
        std::cin >> breadth;
    }

    void displayData() const {
        std::cout << "Length: " << length << ", Breadth: " << breadth << std::endl;
    }

    bool isEqual() const {
        return length == breadth;
    }
};

int main() {
    const int numRectangles = 3; // You can change this
    Rectangle rectangles[numRectangles];

    // Input rectangle data
    std::cout << "Enter rectangle data:\n";
    for (int i = 0; i < numRectangles; ++i) {
        std::cout << "Rectangle " << i + 1 << ":\n";
        rectangles[i].getData();
    }

    // Display rectangles with equal length and breadth
    std::cout << "\nRectangles with equal length and breadth:\n";
    for (int i = 0; i < numRectangles; ++i) {
        if (rectangles[i].isEqual()) {
            rectangles[i].displayData();
        }
    }

    return 0;
}
