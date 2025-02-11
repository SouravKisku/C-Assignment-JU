#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file!" << std::endl;
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    std::string line;

    while (std::getline(file, line)) {
        lineCount++;
        charCount += line.length() + 1; // +1 for the newline character

        // Count words in the line
        std::string word;
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                if (!word.empty()) {
                    wordCount++;
                    word.clear();
                }
            } else {
                word += line[i];
            }
        }
        if (!word.empty()) {
            wordCount++; // Add the last word of the line
        }
    }

    file.close();

    std::cout << "Character count: " << charCount << std::endl;
    std::cout << "Word count: " << wordCount << std::endl;
    std::cout << "Line count: " << lineCount << std::endl;

    return 0;
}
