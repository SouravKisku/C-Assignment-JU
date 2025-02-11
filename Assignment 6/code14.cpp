#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& n) : name(n) {}

    virtual void displayInfo() const {
        std::cout << "Person: Name = " << name << std::endl;
    }
    virtual ~Person(){}
};

class Employee : virtual public Person {
protected:
    int employeeID;

public:
    Employee(const std::string& n, int id) : Person(n), employeeID(id) {}

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << "Employee: ID = " << employeeID << std::endl;
    }
    virtual ~Employee(){}
};

class Student : virtual public Person {
protected:
    int studentID;

public:
    Student(const std::string& n, int id) : Person(n), studentID(id) {}

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << "Student: ID = " << studentID << std::endl;
    }
    virtual ~Student(){}
};

class Manager : public Employee, public Student {
private:
    int managerLevel;

public:
    Manager(const std::string& n, int empId, int studId, int level)
        : Person(n), Employee(n, empId), Student(n, studId), managerLevel(level) {}

    void displayInfo() const override {
        Employee::displayInfo();
        Student::displayInfo();
        std::cout << "Manager: Level = " << managerLevel << std::endl;
    }
    ~Manager(){}
};

int main() {
    Manager manager("Alice", 123, 456, 5);
    manager.displayInfo();

    return 0;
}
