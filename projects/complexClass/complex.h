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
    Complex operator+ (const Complex& c) const;
    Complex operator- (const Complex& c) const;
    Complex& operator= (const Complex& c);
    bool operator ==(const Complex& c) const;
    bool operator !=(const Complex &c) const;
    friend ostream& operator<< (ostream& os,Complex c);
};
#endif