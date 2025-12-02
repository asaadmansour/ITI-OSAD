#include "list.h"
#include <iostream>
#include <stdexcept>
using namespace std;
List::List() {
    capacity = INITIAL_SIZE;
    size = 0;
    elements = new Element[INITIAL_SIZE];
}
List::~List() {
    for(int i = 0; i < size; i++) {
            if(elements[i].dataType == INT) {
                delete (int*)elements[i].data;      
            } else if(elements[i].dataType == FLOAT) {
                delete (float*)elements[i].data;   
            } else if(elements[i].dataType == STRING) {
                delete[] (char*)elements[i].data;  
            } else if(elements[i].dataType == BOOL) {
                delete (bool*)elements[i].data;
            }
        }
    delete[] elements; 
    }
void List::resize() {
    Element* oldElements = elements;             
    int newCapacity = capacity * 2;              
    Element* newElements = new Element[newCapacity]; 
    for(int i = 0; i < size; i++) {
        newElements[i] = oldElements[i];  
    }
    delete[] oldElements;      
    elements = newElements;    
    capacity = newCapacity;    
}
void List::append(const int value){
    if(size == capacity) 
        resize();
    int *stored = new int(value);
    elements[size].data = stored;
    elements[size].dataType = INT;
    size++;
}
void List::append(const float value){
    if(size == capacity) 
        resize();
    float *stored = new float(value);
    elements[size].data = stored;
    elements[size].dataType = FLOAT;
    size++;
}
void List::append(const char* str){
    if(size == capacity) 
        resize();
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    char *newStr = new char[len+1];
    for(int i=0;i<len;i++) {
        newStr[i] = str[i];
    }
    newStr[len] = '\0';
    elements[size].data = newStr;
    elements[size].dataType = STRING;
    size++; 
}

void List::append(const bool value){
    if(size == capacity) 
        resize();
    bool *stored = new bool(value);
    elements[size].data = stored;
    elements[size].dataType = BOOL;
    size++;
}
void List::print() {
    for(int i=0;i<size;i++) {
        if(elements[i].dataType == INT) {
            cout << *(int*)(elements[i].data);
        } else if(elements[i].dataType == FLOAT) {
            cout << *(float*)(elements[i].data);
        } else if(elements[i].dataType == STRING) {
            cout << (char*)elements[i].data;
        } else if(elements[i].dataType == BOOL) {
            cout << (*(bool*)elements[i].data ? "true" : "false");
        }
        if(i < size - 1) {
            cout << ",";  
        }
    }
    cout << endl;
}
int List::getSize() {
    return size;
}
ElementWrapper List::operator[](int index) const {
    if(index < 0 || index >= size) 
        throw out_of_range("Index out of bounds");
    return ElementWrapper(elements[index].data, elements[index].dataType);
}

void List::set(int index, const int value) {
    if(index < 0 || index >= size) 
        throw out_of_range("Index out of bounds");
    if(elements[index].dataType == INT) {
        delete (int*)elements[index].data;
    } else if(elements[index].dataType == FLOAT) {
        delete (float*)elements[index].data;
    } else if(elements[index].dataType == STRING) {
        delete[] (char*)elements[index].data;
    }
    int *stored = new int(value);
    elements[index].data = stored;
    elements[index].dataType = INT;
}

void List::set(int index, const float value) {
    if(index < 0 || index >= size) 
        throw out_of_range("Index out of bounds");
    if(elements[index].dataType == INT) {
        delete (int*)elements[index].data;
    } else if(elements[index].dataType == FLOAT) {
        delete (float*)elements[index].data;
    } else if(elements[index].dataType == STRING) {
        delete[] (char*)elements[index].data;
    }
    float *stored = new float(value);
    elements[index].data = stored;
    elements[index].dataType = FLOAT;
}

void List::set(int index, const char* str) {
    if(index < 0 || index >= size) 
        throw out_of_range("Index out of bounds");
    if(elements[index].dataType == INT) {
        delete (int*)elements[index].data;
    } else if(elements[index].dataType == FLOAT) {
        delete (float*)elements[index].data;
    } else if(elements[index].dataType == STRING) {
        delete[] (char*)elements[index].data;
    } else if(elements[index].dataType == BOOL) {
        delete (bool*)elements[index].data;
    }
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    char *newStr = new char[len+1];
    for(int i = 0; i < len; i++) {
        newStr[i] = str[i];
    }
    newStr[len] = '\0';
    elements[index].data = newStr;
    elements[index].dataType = STRING;
}

void List::set(int index, const bool value) {
    if(index < 0 || index >= size) 
        throw out_of_range("Index out of bounds");
    if(elements[index].dataType == INT) {
        delete (int*)elements[index].data;
    } else if(elements[index].dataType == FLOAT) {
        delete (float*)elements[index].data;
    } else if(elements[index].dataType == STRING) {
        delete[] (char*)elements[index].data;
    } else if(elements[index].dataType == BOOL) {
        delete (bool*)elements[index].data;
    }
    bool *stored = new bool(value);
    elements[index].data = stored;
    elements[index].dataType = BOOL;
}
bool List::isInteger(const char* str) {
    int i = 0;
    bool hasDigit = false;
    
    while(str[i] == ' ') i++;
    
    if(str[i] == '-' || str[i] == '+') i++;
    
    if(str[i] == '\0') return false;
    
    while(str[i] != '\0') {
        if(str[i] >= '0' && str[i] <= '9') {
            hasDigit = true;
        } else if(str[i] != ' ') {
            return false;
        } else {
            break;
        }
        i++;
    }
    
    while(str[i] == ' ') i++;
    
    return hasDigit && str[i] == '\0';
}
bool List::isFloat(const char* str) {
    int i = 0;
    bool hasDecimal = false;
    bool hasDigit = false;
    
    while(str[i] == ' ') i++;
    
    if(str[i] == '-' || str[i] == '+') i++;
    
    if(str[i] == '\0') return false;
    
    while(str[i] != '\0') {
        if(str[i] == '.') {
            if(hasDecimal) return false;
            hasDecimal = true;
        } else if(str[i] >= '0' && str[i] <= '9') {
            hasDigit = true;
        } else if(str[i] != ' ') {
            return false;
        } else {
            break;
        }
        i++;
    }
    
    while(str[i] == ' ') i++;
    
    return hasDecimal && hasDigit && str[i] == '\0';
}
bool List::isBool(const char* str) {
    
    if(str[0] == 't' && str[1] == 'r' && str[2] == 'u' && str[3] == 'e' && str[4] == '\0') {
        return true;
    }
    
    if(str[0] == 'f' && str[1] == 'a' && str[2] == 'l' && str[3] == 's' && str[4] == 'e' && str[5] == '\0') {
        return true;
    }
    return false;
}

bool List::hasExpression(const char* str) {
    bool hasDigit = false;
    bool hasOperator = false;
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            hasDigit = true;
        } else if(i > 0 && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')) {
            if(hasDigit) {
                hasOperator = true;
            }
        } else if(str[i] != ' ' && !(i == 0 && (str[i] == '+' || str[i] == '-'))) {
            return false;
        }
    }
    return hasDigit && hasOperator;
}

int List::evaluateExpression(const char* str) {
    
    int result = 0;
    int currentNum = 0;
    char operation = '+';
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            currentNum = currentNum * 10 + (str[i] - '0');
        } else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            
            if(operation == '+') {
                result += currentNum;
            } else if(operation == '-') {
                result -= currentNum;
            } else if(operation == '*') {
                result *= currentNum;
            } else if(operation == '/') {
                if(currentNum != 0) result /= currentNum;
            }
            
            operation = str[i];
            currentNum = 0;
        }
    }
    
    
    if(operation == '+') {
        result += currentNum;
    } else if(operation == '-') {
        result -= currentNum;
    } else if(operation == '*') {
        result *= currentNum;
    } else if(operation == '/') {
        if(currentNum != 0) result /= currentNum;
    }
    
    return result;
}

void List::appendAuto(const char* input) {
    
    if(isBool(input)) {
        bool value = (input[0] == 't'); 
        append(value);
    }
    
    else if(hasExpression(input)) {
        int value = evaluateExpression(input);
        append(value);
    }
    
    else if(isInteger(input)) {
        
        int value = 0;
        int i = 0;
        bool negative = false;
        
        
        while(input[i] == ' ') i++;
        
        
        if(input[i] == '-') {
            negative = true;
            i++;
        } else if(input[i] == '+') {
            i++;
        }
        
        
        while(input[i] >= '0' && input[i] <= '9') {
            value = value * 10 + (input[i] - '0');
            i++;
        }
        
        if(negative) value = -value;
        append(value);
        
    } else if(isFloat(input)) {
        
        float value = 0.0f;
        int i = 0;
        bool negative = false;
        
        
        while(input[i] == ' ') i++;
        
        
        if(input[i] == '-') {
            negative = true;
            i++;
        } else if(input[i] == '+') {
            i++;
        }
        
        
        while(input[i] >= '0' && input[i] <= '9') {
            value = value * 10 + (input[i] - '0');
            i++;
        }
        
        
        if(input[i] == '.') {
            i++;
            float decimal = 0.1f;
            while(input[i] >= '0' && input[i] <= '9') {
                value += (input[i] - '0') * decimal;
                decimal *= 0.1f;
                i++;
            }
        }
        
        if(negative) value = -value;
        append(value);
        
    } else {
        
        append(input);
    }
}
