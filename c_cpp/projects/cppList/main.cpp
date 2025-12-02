#include "list.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    List l;
    
    int numElements = 0;
    bool validInput = false;
    char buffer[100];
    
    while(!validInput) {
        cout << "How many elements do you want to add? ";
        cin.getline(buffer, 100);
        
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        int i = 0;
        while(buffer[i] == ' ') i++;
        
        if(buffer[i] == '\0') {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        bool isNegative = false;
        if(buffer[i] == '-') {
            isNegative = true;
            i++;
        } else if(buffer[i] == '+') {
            i++;
        }
        
        if(buffer[i] < '0' || buffer[i] > '9') {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        numElements = 0;
        while(buffer[i] >= '0' && buffer[i] <= '9') {
            numElements = numElements * 10 + (buffer[i] - '0');
            i++;
        }
        
        while(buffer[i] == ' ') i++;
        
        if(buffer[i] != '\0') {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        if(isNegative) numElements = -numElements;
        
        if(numElements <= 0) {
            cout << "Please enter a positive number.\n";
            continue;
        }
        
        validInput = true;
    }
    
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
