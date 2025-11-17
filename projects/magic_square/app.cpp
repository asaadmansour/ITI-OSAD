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
    cin >> n;
    if (cin.fail() || n <= 0 || n % 2 == 0) {
        cout << "Invalid Input!" << endl;
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
