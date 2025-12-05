#include "complex.h"

int main() {
    cout << "=== Complex Number Operator Overloading Demo ===" << endl << endl;
    
    // Create complex numbers
    Complex c1(3, 4);   // 3+4i
    Complex c2(2, 1);   // 2+1i
    Complex c3(5, 0);   // 5+0i (real number)
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl << endl;
    
    // Test multiplication
    cout << "--- Multiplication ---" << endl;
    Complex mult = c1 * c2;
    cout << "c1 * c2 = " << mult << endl << endl;
    
    // Test division
    cout << "--- Division ---" << endl;
    Complex div = c1 / c2;
    cout << "c1 / c2 = " << div << endl << endl;
    
    // Test compound assignment with Complex
    cout << "--- Compound Assignment (Complex) ---" << endl;
    Complex temp1 = c1;
    cout << "temp1 = " << temp1 << endl;
    temp1 += c2;
    cout << "temp1 += c2 => " << temp1 << endl;
    
    Complex temp2 = c1;
    temp2 -= c2;
    cout << "c1 -= c2 => " << temp2 << endl;
    
    Complex temp3 = c1;
    temp3 *= c2;
    cout << "c1 *= c2 => " << temp3 << endl;
    
    Complex temp4 = c1;
    temp4 /= c2;
    cout << "c1 /= c2 => " << temp4 << endl << endl;
    
    // Test compound assignment with real numbers
    cout << "--- Compound Assignment (Real Numbers) ---" << endl;
    Complex temp5 = c1;
    cout << "temp5 = " << temp5 << endl;
    temp5 += 10;
    cout << "temp5 += 10 => " << temp5 << endl;
    
    Complex temp6 = c1;
    temp6 -= 2;
    cout << "c1 -= 2 => " << temp6 << endl;
    
    Complex temp7 = c1;
    temp7 *= 3;
    cout << "c1 *= 3 => " << temp7 << endl;
    
    Complex temp8 = c1;
    temp8 /= 2;
    cout << "c1 /= 2 => " << temp8 << endl << endl;
    
    // Chaining operations
    cout << "--- Chaining Operations ---" << endl;
    Complex chain(10, 5);
    cout << "chain = " << chain << endl;
    chain += 5;
    cout << "chain += 5 => " << chain << endl;
    chain *= 2;
    cout << "chain *= 2 => " << chain << endl;
    chain -= Complex(10, 5);
    cout << "chain -= (10+5i) => " << chain << endl;
    cout << c1[0]<<endl;
    cout << c1[1]<<endl;
    return 0;
}