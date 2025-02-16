#include <iostream>
#include <string>

class Student {
private:
    int rollNo;
    std::string name;
    double marks[3]; // Marks in three subjects
    double average;
    char grade;

public:
    void getData() {
        std::cout << "Enter Roll Number: ";
        std::cin >> rollNo;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter marks for three subjects: ";
        for (int i = 0; i < 3; ++i) {
            std::cin >> marks[i];
        }
        calculateAverage();
        assignGrade();
    }

    void calculateAverage() {
        average = (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    void assignGrade() {
        if (average > 80) {
            grade = 'A';
        } else if (average > 70) {
            grade = 'B';
        } else if (average > 60) {
            grade = 'C';
        } else if (average > 50) {
            grade = 'D';
        } else if (average > 40) {
            grade = 'E';
        } else {
            grade = 'F';
        }
    }

    void displayData() const {
        std::cout << "Name: " << name << ", Average: " << average << ", Grade: " << grade << std::endl;
    }
};

int main() {
    const int numStudents = 5; 
    Student students[numStudents];

    // Input student data
    std::cout << "Enter student data:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Student " << i + 1 << ":\n";
        students[i].getData();
    }

    // Display student data
    std::cout << "\nStudent data:\n";
    for (int i = 0; i < numStudents; ++i) {
        students[i].displayData();
    }

    return 0;
}
