#include "list.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    List l;
    
    int numElements = 0;
    bool validInput = false;
    
    while(!validInput) {
        cout << "How many elements do you want to add? ";
        if(cin >> numElements) {
            if(numElements > 0) {
                validInput = true;
            } else {
                cout << "Please enter a positive number.\n";
            }
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for(int i = 0; i < numElements; i++) {
        char input[100];
        cout << "Enter value " << (i+1) << ": ";
        cin.getline(input, 100);
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
            continue;
        }
        l.appendAuto(input);
    }
    
    cout << "\nYour list: ";
    l.print();
    cout << "Size: " << l.getSize() << endl;
    
    cout << "\nDetected types:" << endl;
    for(int i = 0; i < l.getSize(); i++) {
        cout << "Element " << i+1 << ": ";
        try {
            bool val = l[i];
            cout << (val ? "true" : "false") << " (bool)" << endl;
        } catch(...) {
            try {
                int val = l[i];
                cout << val << " (int)" << endl;
            } catch(...) {
                try {
                    float val = l[i];
                    cout << val << " (float)" << endl;
                } catch(...) {
                    char* val = l[i];
                    cout << val << " (string)" << endl;
                }
            }
        }
    }
    
    return 0;
}
