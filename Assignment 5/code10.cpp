#include <iostream>
#include <cmath> // For pow() and M_PI

class VolumeCalculator {
public:
    // Volume of a cube
    double volume(double side) {
        return side * side * side;
    }

    // Volume of a cuboid
    double volume(double length, double width, double height) {
        return length * width * height;
    }

    // Volume of a cone
    double volume(double radius, double height) {
        return (1.0/3.0) * M_PI * radius * radius * height;
    }

    // Volume of a cylinder
    double volume(double radius, double height, char tag) { // Added a dummy argument to differentiate from cone
        return M_PI * radius * radius * height;
    }

    // Volume of a sphere
    double volume(double radius, int tag) { // Added a dummy argument to differentiate from cone and cylinder
        return (4.0/3.0) * M_PI * radius * radius * radius;
    }
};

int main() {
    VolumeCalculator calc;
    int choice;
    double side, length, width, height, radius;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Volume of Cube\n";
        std::cout << "2. Volume of Cuboid\n";
        std::cout << "3. Volume of Cone\n";
        std::cout << "4. Volume of Cylinder\n";
        std::cout << "5. Volume of Sphere\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter side of cube: ";
                std::cin >> side;
                std::cout << "Volume of cube: " << calc.volume(side) << std::endl;
                break;
            case 2:
                std::cout << "Enter length, width, and height of cuboid: ";
                std::cin >> length >> width >> height;
                std::cout << "Volume of cuboid: " << calc.volume(length, width, height) << std::endl;
                break;
            case 3:
                std::cout << "Enter radius and height of cone: ";
                std::cin >> radius >> height;
                std::cout << "Volume of cone: " << calc.volume(radius, height) << std::endl;
                break;
            case 4:
                std::cout << "Enter radius and height of cylinder: ";
                std::cin >> radius >> height;
                std::cout << "Volume of cylinder: " << calc.volume(radius, height, 'c') << std::endl;
                break;
            case 5:
                std::cout << "Enter radius of sphere: ";
                std::cin >> radius;
                std::cout << "Volume of sphere: " << calc.volume(radius, 1) << std::endl;
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
