#ifndef STRING_H
#define STRING_H
class String {
    private:
        static constexpr int INITIAL_SIZE = 16; 
        static int myStrLen(const char* str);
        
        char *ptr;
        int length;
        int capacity;
    public:
    String();
    String(const char * text);
    String(const String &s);
    ~String();
    String& operator=(const String& s);

};
#endif