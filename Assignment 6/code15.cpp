#include <iostream>
#include <string>
#include <vector>

class Student {
protected:
    std::string name;
    int rollNumber;
    static int nextRollNumber;
public:
    Student(const std::string& n) : name(n) {
        rollNumber = nextRollNumber++;
    }
    virtual ~Student() {}

    virtual void displayInfo() const = 0; // Abstract class due to this pure virtual function

};
int Student::nextRollNumber = 1;

class Engineering : public Student {
private:
    std::string major;
public:
    Engineering(const std::string& n, const std::string& m) : Student(n), major(m) {}

    void displayInfo() const override {
        std::cout << "Engineering Student: " << name << ", Roll Number: " <<  Student::nextRollNumber-1 <<", Major: " << major << std::endl;
    }
};

class Medicine : public Student {
private:
    std::string specialization;
public:
    Medicine(const std::string& n, const std::string& s) : Student(n), specialization(s) {}

    void displayInfo() const override {
        std::cout << "Medicine Student: " << name << ", Roll Number: " << Student::nextRollNumber-1 << ", Specialization: " << specialization << std::endl;
    }
};

class Science : public Student {
private:
    std::string field;
public:
    Science(const std::string& n, const std::string& f) : Student(n), field(f) {}

    void displayInfo() const override {
        std::cout << "Science Student: " << name << ", Roll Number: " <<  Student::nextRollNumber-1 <<", Field: " << field << std::endl;
    }
};

int main() {
    std::vector<Student*> students;

    students.push_back(new Engineering("Alice", "Computer Science"));
    students.push_back(new Medicine("Bob", "Cardiology"));
    students.push_back(new Science("Charlie", "Physics"));

    for (Student* s : students) {
        s->displayInfo();
        delete s;
    }

    return 0;
}
