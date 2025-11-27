#include "complex.h"
Complex::Complex() {
    real = 0;
    imaginary = 0;
}
Complex::Complex(int reall) {
    real = reall;
    imaginary = 0;
}
Complex::Complex(int reall,int imaginaryy) {
    real = reall;
    imaginary = imaginaryy;
}
Complex::Complex(const Complex& c){
    real = c.real;
    imaginary = c.imaginary;
}
void Complex::setReal(int realNumber) {
    real = realNumber;
}
void Complex::setImaginary(int imaginaryNumber) {
    imaginary = imaginaryNumber;
}
int Complex::getImaginary() const {
    return imaginary;
}
int Complex::getReal() const {
    return real;
}
Complex Complex::operator+ (const Complex& c) const {
    return Complex(real + c.real, imaginary + c.imaginary);
}
Complex Complex::operator- (const Complex& c) const {
    return Complex(real - c.real, imaginary - c.imaginary);
}
Complex& Complex::operator= (const Complex& c){
    if (this != &c) {
        real = c.real;
        imaginary = c.imaginary;
    }
    return *this;
}
bool Complex::operator== (const Complex& c) const {
    return real == c.real && imaginary == c.imaginary;
}
bool Complex::operator!= (const Complex& c) const {
    return !(*this == c);  
}
ostream& operator<<(ostream& os,Complex c) {
    os << c.real;
    if (c.imaginary >= 0) {
        os << "+" << c.imaginary << "i";
    } else {
        os << c.imaginary << "i";
    }
    return os;
}