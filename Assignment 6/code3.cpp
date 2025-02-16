#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    Rectangle rects[5];
    
    // Taking input for 5 rectangles
    cout << "Enter length and breadth of 5 rectangles:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Rectangle " << i + 1 << " (length breadth): ";
        cin >> rects[i].length >> rects[i].breadth;
    }
    
    // Display rectangles that are squares
    cout << "\nRectangles that are squares:" << endl;
    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (rects[i].length == rects[i].breadth) {
            cout << "Rectangle " << i + 1 << " (" << rects[i].length << " x " << rects[i].breadth << ")" << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No rectangles are squares." << endl;
    }
    
    return 0;
}
