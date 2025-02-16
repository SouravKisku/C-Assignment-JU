#include <iostream>

class Outer {
private:
    int num1, num2, num3;

public:
    Outer(int n1, int n2, int n3) : num1(n1), num2(n2), num3(n3) {}

    class Inner {
    public:
        int findGreatest(int a, int b, int c) {
            if (a > b && a > c) {
                return a;
            } else if (b > a && b > c) {
                return b;
            } else {
                return c;
            }
        }
    };

    void displayGreatest() {
        Inner inner;
        int greatest = inner.findGreatest(num1, num2, num3);
        std::cout << "Greatest number: " << greatest << std::endl;
    }
};

int main() {
    int n1, n2, n3;
    
    std::cout << "Enter three numbers: " << std::endl;
    std::cout << "Number 1: ";
    std::cin >> n1;
    std::cout << "Number 2: ";
    std::cin >> n2;
    std::cout << "Number 3: ";
    std::cin >> n3;

    Outer outer(n1, n2, n3);
    outer.displayGreatest(); 

    return 0;
}
