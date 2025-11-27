#include "complex.h"
int main() {
    Complex c(3,5);
    Complex c1(3,5);
    Complex c2;
    c2 = c1+c;
    cout << c2<<endl;
    return 0;
}