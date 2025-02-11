#include <iostream>
#include <algorithm> // Required for std::sort

class Number_List {
private:
    int* arr;
    int size;

public:
    // Constructor to create the array at runtime
    Number_List(int s) : size(s) {
        arr = new int[size];
    }

    // Function to take input from the user
    void takeInput() {
        std::cout << "Enter " << size << " integers:\n";
        for (int i = 0; i < size; ++i) {
            std::cin >> arr[i];
        }
    }

    // Function to sort the array
    void sortArray() {
        std::sort(arr, arr + size);
    }

    // Function to find the minimum element
    int findMin() {
        int min = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    // Function to find the maximum element
    int findMax() {
        int max = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    // Function to display the array
    void displayArray() {
        std::cout << "Array elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Destructor to release the dynamically allocated memory
    ~Number_List() {
        delete[] arr;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    Number_List myList(size);
    myList.takeInput();

    std::cout << "\nOriginal ";
    myList.displayArray();

    myList.sortArray();
    std::cout << "Sorted ";
    myList.displayArray();

    std::cout << "Minimum element: " << myList.findMin() << std::endl;
    std::cout << "Maximum element: " << myList.findMax() << std::endl;

    return 0;
}
