#include <iostream>
#include <string>
#include <vector>

class Marks {
protected:
    int rollNumber;
    std::string name;
    static int nextRollNumber;

public:
    Marks() : rollNumber(0), name("") {}

    void setRollNumber() {
        rollNumber = nextRollNumber++;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    void setName(const std::string& n) {
        name = n;
    }

    std::string getName() const {
        return name;
    }

    virtual double getTotalMarks() const = 0;
    virtual double getAverageMarks() const = 0;

    virtual void display() const {
        std::cout << "Roll Number: " << rollNumber << ", Name: " << name;
    }
    virtual ~Marks() {} //Virtual Destructor
};

int Marks::nextRollNumber = 1;

class Physics : public Marks {
private:
    double physicsMarks;

public:
    void setPhysicsMarks(double marks) {
        physicsMarks = marks;
    }

    double getPhysicsMarks() const {
        return physicsMarks;
    }

    double getTotalMarks() const override {
        return physicsMarks;
    }

    double getAverageMarks() const override {
        return physicsMarks;
    }

    void display() const override {
        Marks::display();
        std::cout << ", Physics Marks: " << physicsMarks;
    }
};

class Chemistry : public Marks {
private:
    double chemistryMarks;

public:
    void setChemistryMarks(double marks) {
        chemistryMarks = marks;
    }

    double getChemistryMarks() const {
        return chemistryMarks;
    }

    double getTotalMarks() const override {
        return chemistryMarks;
    }

    double getAverageMarks() const override {
        return chemistryMarks;
    }

    void display() const override {
        Marks::display();
        std::cout << ", Chemistry Marks: " << chemistryMarks;
    }
};

class Mathematics : public Marks {
private:
    double mathematicsMarks;

public:
    void setMathematicsMarks(double marks) {
        mathematicsMarks = marks;
    }

    double getMathematicsMarks() const {
        return mathematicsMarks;
    }

    double getTotalMarks() const override {
        return mathematicsMarks;
    }

    double getAverageMarks() const override {
        return mathematicsMarks;
    }

    void display() const override {
        Marks::display();
        std::cout << ", Mathematics Marks: " << mathematicsMarks;
    }
};

int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    std::cin.ignore();

    std::vector<Physics*> physicsStudents;
    std::vector<Chemistry*> chemistryStudents;
    std::vector<Mathematics*> mathematicsStudents;

    double totalPhysicsMarks = 0, totalChemistryMarks = 0, totalMathematicsMarks = 0;

    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        double physicsMarks, chemistryMarks, mathematicsMarks;

        std::cout << "\nEnter details for student " << i + 1 << ":\n";
        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Physics Marks: ";
        std::cin >> physicsMarks;
        std::cout << "Chemistry Marks: ";
        std::cin >> chemistryMarks;
        std::cout << "Mathematics Marks: ";
        std::cin >> mathematicsMarks;
        std::cin.ignore();

        Physics* p = new Physics();
        p->setName(name);
        p->setRollNumber();
        p->setPhysicsMarks(physicsMarks);
        physicsStudents.push_back(p);
        totalPhysicsMarks += p->getPhysicsMarks();

        Chemistry* c = new Chemistry();
        c->setName(name);
        c->setRollNumber();
        c->setChemistryMarks(chemistryMarks);
        chemistryStudents.push_back(c);
        totalChemistryMarks += c->getChemistryMarks();

        Mathematics* m = new Mathematics();
        m->setName(name);
        m->setRollNumber();
        m->setMathematicsMarks(mathematicsMarks);
        mathematicsStudents.push_back(m);
        totalMathematicsMarks += m->getMathematicsMarks();
    }

    double classAveragePhysics = totalPhysicsMarks / numStudents;
    double classAverageChemistry = totalChemistryMarks / numStudents;
    double classAverageMathematics = totalMathematicsMarks / numStudents;

    std::cout << "\nStudent Details:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Physics Student: ";
        physicsStudents[i]->display();
        std::cout << std::endl;

        std::cout << "Chemistry Student: ";
        chemistryStudents[i]->display();
        std::cout << std::endl;

        std::cout << "Mathematics Student: ";
        mathematicsStudents[i]->display();
        std::cout << std::endl;
    }

    std::cout << "\nClass Average Marks:\n";
    std::cout << "Physics: " << classAveragePhysics << std::endl;
    std::cout << "Chemistry: " << classAverageChemistry << std::endl;
    std::cout << "Mathematics: " << classAverageMathematics << std::endl;

      // Clean up memory
    for (Physics* p : physicsStudents) delete p;
    for (Chemistry* c : chemistryStudents) delete c;
    for (Mathematics* m : mathematicsStudents) delete m;

    return 0;
}
