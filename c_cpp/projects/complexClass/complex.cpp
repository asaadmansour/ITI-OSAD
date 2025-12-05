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

Complex Complex::operator* (const Complex& c) const {
    int newReal = real * c.real - imaginary * c.imaginary;
    int newImag = real * c.imaginary + imaginary * c.real;
    return Complex(newReal, newImag);
}

Complex Complex::operator/ (const Complex& c) const {
    int denominator = c.real * c.real + c.imaginary * c.imaginary;
    if (denominator == 0) {
        
        return Complex(0, 0);
    }
    int newReal = (real * c.real + imaginary * c.imaginary) / denominator;
    int newImag = (imaginary * c.real - real * c.imaginary) / denominator;
    return Complex(newReal, newImag);
}

Complex& Complex::operator+= (const Complex& c) {
    real += c.real;
    imaginary += c.imaginary;
    return *this;
}

Complex& Complex::operator-= (const Complex& c) {
    real -= c.real;
    imaginary -= c.imaginary;
    return *this;
}

Complex& Complex::operator*= (const Complex& c) {
    *this = *this * c;
    return *this;
}

Complex& Complex::operator/= (const Complex& c) {
    *this = *this / c;
    return *this;
}

Complex& Complex::operator+= (int realNum) {
    real += realNum;
    return *this;
}

Complex& Complex::operator-= (int realNum) {
    real -= realNum;
    return *this;
}

Complex& Complex::operator*= (int realNum) {
    real *= realNum;
    imaginary *= realNum;
    return *this;
}

Complex& Complex::operator/= (int realNum) {
    if (realNum != 0) {
        real /= realNum;
        imaginary /= realNum;
    }
    return *this;
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
int Complex::operator[](const int &index) const {
    if(index == 0) 
        return this->real;
    else if(index == 1)
        return imaginary;
    else 
        return -1;
};