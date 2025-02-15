#include <iostream>
#include <string>

class String {
private:
    std::string str;

public:
    // Constructor
    String(const std::string& s) : str(s) {}

    // Function to display the string
    void display() const {
        std::cout << str << std::endl;
    }

    // Function to join two strings
    String join(const String& other) const {
        return String(str + " " + other.str);
    }
};

int main() {
    std::string input1, input2;

    std::cout << "Enter the first string: ";
    std::getline(std::cin, input1);
    String str1(input1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, input2);
    String str2(input2);

    std::cout << "str1: ";
    str1.display();

    std::cout << "str2: ";
    str2.display();

    String str3 = str1.join(str2);
    std::cout << "str1 + str2 : ";
    str3.display();

    return 0;
}
