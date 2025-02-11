#include <iostream>
#include <string>
#include <algorithm>

class MyString {
private:
    std::string str;

public:
    MyString() : str("") {}
    MyString(const std::string& s) : str(s) {}

    // Overload the + operator
    MyString operator+(const MyString& other) const {
        std::string concatenated = str + other.str;
        std::reverse(concatenated.begin(), concatenated.end());
        return MyString(concatenated);
    }

    // Function to display the string
    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2("World");

    MyString str3 = str1 + str2; // Concatenate and reverse

    std::cout << "Concatenated and reversed string: ";
    str3.display();

    return 0;
}
