#include <iostream>
using namespace std;

// function to print inverted triangle
void printInvTriangle(int n)
{
    // outer loop to go through every row
    for (int i = 0; i < n; i++) {
        // print leading spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
        // print stars
        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            cout << "*";
        }
        
        cout << endl;
    }
}

// driver code
int main()
{
    printInvTriangle(6);
    return 0;
}
