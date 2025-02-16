#include <iostream>
#include <string>
#include <vector>
#include <limits>

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

    virtual void displayInfo() const = 0;
};
int Student::nextRollNumber = 1;

class Engineering : public Student {
private:
    std::string major;
public:
    Engineering(const std::string& n, const std::string& m) : Student(n), major(m) {}

    void displayInfo() const override {
        std::cout << "Engineering Student: " << name << ", Roll Number: " << rollNumber << ", Major: " << major << std::endl;
    }
};

class Medicine : public Student {
private:
    std::string specialization;
public:
    Medicine(const std::string& n, const std::string& s) : Student(n), specialization(s) {}

    void displayInfo() const override {
        std::cout << "Medicine Student: " << name << ", Roll Number: " << rollNumber << ", Specialization: " << specialization << std::endl;
    }
};

class Science : public Student {
private:
    std::string field;
public:
    Science(const std::string& n, const std::string& f) : Student(n), field(f) {}

    void displayInfo() const override {
        std::cout << "Science Student: " << name << ", Roll Number: " << rollNumber << ", Field: " << field << std::endl;
    }
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<Student*> students;
    int numStudents;

    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    clearInputBuffer();

    for (int i = 0; i < numStudents; ++i) {
        std::string name, discipline, specialization;
        int choice;

        std::cout << "\nStudent " << i+1 << ":\n";
        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        std::cout << "Choose discipline (1: Engineering, 2: Medicine, 3: Science): ";
        std::cin >> choice;
        clearInputBuffer();

        std::cout << "Enter specialization/major/field: ";
        std::getline(std::cin, specialization);

        switch(choice) {
            case 1:
                students.push_back(new Engineering(name, specialization));
                break;
            case 2:
                students.push_back(new Medicine(name, specialization));
                break;
            case 3:
                students.push_back(new Science(name, specialization));
                break;
            default:
                std::cout << "Invalid choice. Skipping this student.\n";
                --i; // Decrement i to retry this iteration
        }
    }

    std::cout << "\nStudent Information:\n";
    for (Student* s : students) {
        s->displayInfo();
        delete s;
    }

    return 0;
}
