#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class Complex {
    private:
        int real;
        int imaginary;
    public:

    //constructors
    Complex();
    Complex(int real);
    Complex(int real,int imaginary);
    Complex(const Complex& c);

    //getters
    int getReal() const;
    int getImaginary() const;

    //setters
    void setReal(int realNumber) ;
    void setImaginary(int imaginaryNumber) ;

    //operators
    
    // Arithmetic operators
    Complex operator+ (const Complex& c) const;
    Complex operator- (const Complex& c) const;
    Complex operator* (const Complex& c) const;
    Complex operator/ (const Complex& c) const;
    
    // Assignment operator
    Complex& operator= (const Complex& c);
    
    // Compound assignment operators (Complex)
    Complex& operator+= (const Complex& c);
    Complex& operator-= (const Complex& c);
    Complex& operator*= (const Complex& c);
    Complex& operator/= (const Complex& c);
    
    // Compound assignment operators (real numbers)
    Complex& operator+= (int realNum);
    Complex& operator-= (int realNum);
    Complex& operator*= (int realNum);
    Complex& operator/= (int realNum);
    
    // Comparison operators
    bool operator ==(const Complex& c) const;
    bool operator !=(const Complex &c) const;
    int operator [](const int &index) const;
    
    // Stream operator
    friend ostream& operator<< (ostream& os,Complex c);
};
#endif