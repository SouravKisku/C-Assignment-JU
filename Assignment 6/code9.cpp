#include <iostream>

class Mammals {
public:
    void displayMammal() {
        std::cout << "I am a mammal" << std::endl;
    }
};

class MarineAnimal {
public:
    void displayMarineAnimal() {
        std::cout << "I am a marine animal" << std::endl;
    }
};

class BlueWhale : public Mammals, public MarineAnimal {
public:
    void displayBlueWhale() {
        std::cout << "I belong to both the categories: Mammals as well as Marine Animals" << std::endl;
    }
};

int main() {
    Mammals mammal;
    MarineAnimal marineAnimal;
    BlueWhale blueWhale;

    std::cout << "Mammal object: ";
    mammal.displayMammal();

    std::cout << "MarineAnimal object: ";
    marineAnimal.displayMarineAnimal();

    std::cout << "BlueWhale object: ";
    blueWhale.displayBlueWhale();

    std::cout << "BlueWhale object (Mammal): ";
    blueWhale.displayMammal();

    std::cout << "BlueWhale object (MarineAnimal): ";
    blueWhale.displayMarineAnimal();

    return 0;
}
