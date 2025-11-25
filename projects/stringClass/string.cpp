#include "string.h"
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
    ptr = new char[INITIAL_SIZE];
    ptr[0] = '\0';
    length = 0;
    capacity =  INITIAL_SIZE;

}
String::String(const char *text) {
    int textLen = myStrLen(text);
    capacity = max(INITIAL_SIZE,textLen+1);
    ptr = new char[capacity];
    for(int i=0;i<textLen;i++) {
        ptr[i] = text[i];
    }
    ptr[textLen] = '\0';
    length = textLen;
}
String::~String() {
    delete[] ptr;
}