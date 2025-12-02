//app.cpp
#include <iostream>
using namespace std;
#include "terminal.h"
#include <thread>
#include <chrono>
void delay(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}
int main() {
    int n = 0;
    int number = 1;
    cout << "Enter a positive odd number: " << endl;
    
    string input;
    getline(cin, input);
    
    int i = 0;
    while (i < input.length() && input[i] == ' ') i++;
    
    if (i >= input.length() || input[i] < '0' || input[i] > '9') {
        cout << "Invalid Input!" << endl;
        return 0;
    }
    
    if (input[i] == '0' && i + 1 < input.length() && input[i+1] >= '0' && input[i+1] <= '9') {
        cout << "Invalid Input! Leading zeros are not allowed." << endl;
        return 0;
    }
    
    n = 0;
    while (i < input.length() && input[i] >= '0' && input[i] <= '9') {
        n = n * 10 + (input[i] - '0');
        i++;
    }
    
    while (i < input.length() && input[i] == ' ') i++;
    
    if (i < input.length()) {
        cout << "Invalid Input! Please enter only a number." << endl;
        return 0;
    }
    
    if (n <= 2 || n % 2 == 0) {
        cout << "Invalid Input! Number must be odd and greater than 2." << endl;
        return 0;
    }
    terminal_clear();
    int row = 0;
    int col = n / 2;
    terminal_draw_at(row, col, number, n);
    delay(300);
    number++;
    while (number <= n * n) {
        if ((number - 1) % n != 0) {
            
            row = (row - 1 + n) % n; 
            col = (col + 1) % n;
        } else {
            row = (row + 1) % n;
        }
        terminal_draw_at(row, col, number, n);
        delay(300);
        number++;
    }
    terminal_move_to(0, n * 2 + 1);  
    cout << endl; 
    return 0;
}
