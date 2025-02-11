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
        return String(str + other.str);
    }
};

int main() {
    String str1("Hello, ");
    String str2("World!");

    std::cout << "str1: ";
    str1.display();

    std::cout << "str2: ";
    str2.display();

    String str3 = str1.join(str2);
    std::cout << "str1 + str2: ";
    str3.display();

    return 0;
}
