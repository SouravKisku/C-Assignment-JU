#include <iostream>
#include <string>

class Employee {
private:
    int empId;
    std::string name;
    double salary;

public:
    void getData() {
        std::cout << "Enter Employee ID: ";
        std::cin >> empId;
        std::cout << "Enter Employee Name: ";
        std::cin.ignore(); // Consume the newline character left by previous input
        std::getline(std::cin, name);
        std::cout << "Enter Employee Salary: ";
        std::cin >> salary;
    }

    void displayData() const {
        std::cout << "ID: " << empId << ", Name: " << name << std::endl;
    }

    double getSalary() const {
        return salary;
    }
};

int main() {
    const int numEmployees = 3; // You can change this to the desired number of employees
    Employee employees[numEmployees];

    // Input employee data
    std::cout << "Enter employee data:\n";
    for (int i = 0; i < numEmployees; ++i) {
        std::cout << "Employee " << i + 1 << ":\n";
        employees[i].getData();
    }

    // Display names and IDs of employees with salaries above 50000
    std::cout << "\nEmployees with salaries above 50000:\n";
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].getSalary() > 50000.0) {
            employees[i].displayData();
        }
    }

    return 0;
}
