#include <iostream>

class Fruit {
protected:
    int numberOfFruits;

public:
    Fruit() : numberOfFruits(0) {}

    void setNumberOfFruits(int count) {
        numberOfFruits = count;
    }

    int getNumberOfFruits() const {
        return numberOfFruits;
    }
};

class Apples : public Fruit {
private:
    int numberOfApples;

public:
    Apples() : numberOfApples(0) {}

    void setNumberOfApples(int count) {
        numberOfApples = count;
        setNumberOfFruits(getNumberOfFruits() + count); // Update total fruit count in base class
    }

    int getNumberOfApples() const {
        return numberOfApples;
    }
};

class Mangoes : public Fruit {
private:
    int numberOfMangoes;

public:
    Mangoes() : numberOfMangoes(0) {}

    void setNumberOfMangoes(int count) {
        numberOfMangoes = count;
        setNumberOfFruits(getNumberOfFruits() + count); // Update total fruit count in base class
    }

    int getNumberOfMangoes() const {
        return numberOfMangoes;
    }
};

int main() {
    Apples apples;
    Mangoes mangoes;

    apples.setNumberOfApples(10);
    mangoes.setNumberOfMangoes(15);

    std::cout << "Number of Apples: " << apples.getNumberOfApples() << std::endl;
    std::cout << "Number of Mangoes: " << mangoes.getNumberOfMangoes() << std::endl;
    std::cout << "Total number of fruits in the basket: " << apples.getNumberOfFruits() << std::endl; // Or mangoes.getNumberOfFruits(), as they share the same base class instance

    return 0;
}
