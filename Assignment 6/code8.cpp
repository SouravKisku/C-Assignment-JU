#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Record {
    int id;
    std::string name;
    std::string data;

    // Overload the output stream operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Record& record) {
        os << record.id << "," << record.name << "," << record.data;
        return os;
    }

    // Overload the input stream operator for reading from a string
    friend std::istream& operator>>(std::istream& is, Record& record) {
        std::string line;
        std::getline(is, line); // Read the entire line
        std::stringstream ss(line); // Create a stringstream from the line
        std::string token;

        // Parse the ID
        std::getline(ss, token, ',');
        record.id = std::stoi(token);

        // Parse the Name
        std::getline(ss, record.name, ',');

        // Parse the Data
        std::getline(ss, record.data, ',');

        return is;
    }
};

std::string filename = "data.txt";

// Function to add a new record
void addRecord() {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    Record newRecord;
    std::cout << "Enter ID: ";
    std::cin >> newRecord.id;
    std::cout << "Enter Name: ";
    std::cin.ignore(); // Consume the newline character
    std::getline(std::cin, newRecord.name);
    std::cout << "Enter Data: ";
    std::getline(std::cin, newRecord.data);

    file << newRecord << std::endl; // Output the Record object
    file.close();
    std::cout << "Record added successfully." << std::endl;
}

// Function to view all records
void viewAllRecords() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        Record record;
        std::stringstream ss(line);
        ss >> record;

        std::cout << record << std::endl; //output the record object
    }

    file.close();
}

// Function to delete a particular record
void deleteRecord() {
    int idToDelete;
    std::cout << "Enter ID of record to delete: ";
    std::cin >> idToDelete;
    std::cin.ignore();

    std::ifstream fileIn(filename);
    if (!fileIn.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    std::ofstream fileOut("temp.txt");
    if (!fileOut.is_open()) {
        std::cerr << "Error opening temporary file for writing!" << std::endl;
        fileIn.close();
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(fileIn, line)) {
        Record record;
        std::stringstream ss(line);
        ss >> record;
        if (record.id != idToDelete) {
            fileOut << record << std::endl;
        } else {
            found = true;
        }
    }

    fileIn.close();
    fileOut.close();

    if (found) {
        std::remove(filename.c_str());
        std::rename("temp.txt", filename.c_str());
        std::cout << "Record deleted successfully." << std::endl;
    } else {
        std::remove("temp.txt");
        std::cout << "Record with ID " << idToDelete << " not found." << std::endl;
    }
}

// Function to search for a record
void searchRecord() {
    int idToSearch;
    std::cout << "Enter ID of record to search: ";
    std::cin >> idToSearch;
    std::cin.ignore();

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(file, line)) {
        Record record;
        std::stringstream ss(line);
        ss >> record;
        if (record.id == idToSearch) {
            std::cout << "Record found: " << record << std::endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        std::cout << "Record with ID " << idToSearch << " not found." << std::endl;
    }
}

// Function to update a record
void updateRecord() {
    int idToUpdate;
    std::cout << "Enter ID of record to update: ";
    std::cin >> idToUpdate;
    std::cin.ignore();

    std::ifstream fileIn(filename);
    if (!fileIn.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    std::ofstream fileOut("temp.txt");
    if (!fileOut.is_open()) {
        std::cerr << "Error opening temporary file for writing!" << std::endl;
        fileIn.close();
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(fileIn, line)) {
        Record record;
        std::stringstream ss(line);
        ss >> record;
        if (record.id == idToUpdate) {
            std::cout << "Enter new Name: ";
            std::getline(std::cin, record.name);
            std::cout << "Enter new Data: ";
            std::getline(std::cin, record.data);

            fileOut << record << std::endl;
            found = true;
            std::cout << "Record updated successfully." << std::endl;
        } else {
            fileOut << record << std::endl;
        }
    }

    fileIn.close();
    fileOut.close();

    if (found) {
        std::remove(filename.c_str());
        std::rename("temp.txt", filename.c_str());
    } else {
        std::remove("temp.txt");
        std::cout << "Record with ID " << idToUpdate << " not found." << std::endl;
    }
}

int main() {
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add new record\n";
        std::cout << "2. View all records\n";
        std::cout << "3. Delete particular record\n";
        std::cout << "4. Search record\n";
        std::cout << "5. Update record\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewAllRecords();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                updateRecord();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
