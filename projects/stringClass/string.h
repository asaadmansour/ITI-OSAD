#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
class String {
    private:
        static constexpr int INITIAL_SIZE = 16; 
        static int myStrLen(const char* str);
        
        char *ptr;
        int length;
        int capacity;
    public:
    // constructors
    String();
    String(const char * text);
    String(const String &s);
    String& operator=(const String& s);
    //destructor
    ~String();

    //access methods

    int getLength() const;
    int getCapacity() const;
    bool isEmpty() const;
    void clear();
    friend ostream& operator<<(ostream& os, const String& s);
    char& operator[](int index);
    const char& operator[](int index) const;
    bool operator==(const String& str) const;
    bool operator!=(const String& str) const;
    //Modification functions
    
    String& append(const String& s);
   
};
#endif