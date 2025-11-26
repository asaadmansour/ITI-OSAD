#include "string.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;
int String::myStrLen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
String::String() {
    capacity = 0;
    ptr = new char[INITIAL_SIZE];
    ptr[0] = '\0';
    length = 0;
    capacity =  INITIAL_SIZE;

}
String::String(const char *text) {
    if (text == nullptr) {
        throw invalid_argument("Cannot create String from nullptr");
    }
    int textLen = myStrLen(text);
    capacity = max(INITIAL_SIZE,textLen+1);
    ptr = new char[capacity];
    for(int i=0;i<textLen;i++) {
        ptr[i] = text[i];
    }
    ptr[textLen] = '\0';
    length = textLen;
}

String::String(const String &s) {
    length = s.length;
    capacity = s.capacity;
    ptr = new char[capacity];
    for(int i=0;i<length;i++) {
        ptr[i] = s.ptr[i];
    }
    ptr[length] = '\0';
}
String& String::operator=(const String &s) {
    if (this == &s) {
    return *this; 
    }
    delete[] ptr;
    length = s.length;
    capacity = s.capacity;
    ptr = new char[capacity];
    for(int i=0;i<length;i++) {
        ptr[i] = s.ptr[i];
    }
    ptr[length] = '\0';
    return *this;
}
String::~String() {
    delete[] ptr;
}

// Access Functions

int String::getLength() const {
    return length;
}

int String::getCapacity() const {
    return capacity;
}

bool String::isEmpty() const {
    return length == 0;
}

char& String::operator[](int index) {
    if (index < 0 || index >= length) {
        throw out_of_range("Index out of bounds");
    }
    return ptr[index];
}

const char& String::operator[](int index) const {
    if (index < 0 || index >= length) {
        throw out_of_range("Index out of bounds");
    }
    return ptr[index];
}
ostream& operator<<(ostream& os, const String& s) {
    os << s.ptr;  
    return os;
} 

//Modification functions

String& String::append(const String& s) {
    int newLength = length +s.length;
    int newCapacity = newLength+1;
    char *newPtr = new char[newCapacity];
    for(int i=0;i<length;i++) {
        newPtr[i] = ptr[i];
    }
    for(int i=0;i<s.length;i++) {
        newPtr[length+i] = s.ptr[i];
    }
    newPtr[newLength] = '\0';
    delete[] ptr;
    ptr = newPtr;
    length = newLength;
    capacity = newCapacity;
    return *this;
}
bool String::operator==(const String&str) const {
    if(length != str.length)
        return false;
    for (int i = 0; i < length; ++i) {
        if (ptr[i] != str.ptr[i])
            return false;
    }
    return true;
}
bool String::operator!=(const String& str) const {
       return !(*this == str);  
   }

void String::clear() {
    delete[] ptr;
    ptr = new char[INITIAL_SIZE];
    ptr[0] = '\0'; 
    length = 0;
    capacity = INITIAL_SIZE;
}