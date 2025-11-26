#include "string.h"
#include <iostream>

using namespace std;

int main() {
    // Test 1: Default constructor
    String s1;
    cout << "s1 created (empty string)" << endl;

    // Test 2: Parameterized constructor
    String s2("helloasaadasaadasaad");
    cout << "s2 created with initial value: \"helloasaadasaadasaad\"" << endl;

    // Test 3: Copy constructor
    String s3(s2);
    cout << "s3 created as a copy of s2" << endl;

    // Test 4: Assignment operator
    String s4("world");
    s4 = s2;  // s4 now has the same value as s2
    cout << "s4 assigned from s2" << endl;

    // Test 5: Self-assignment
    s2 = s2;  // should be handled safely
    cout << "s2 self-assigned successfully" << endl;

    // Test 6: Exception when creating a string with nullptr (uncomment to test)
//  String s5(nullptr);

    cout << "s2 length: " << s2.getLength() << endl;
    cout << "s2 capacity: " << s2.getCapacity() << endl;
    cout << "s2 is empty: " << (s2.isEmpty() ? "true" : "false") << endl;
    cout << "s1 is empty: " << (s1.isEmpty() ? "true" : "false") << endl;

    // Test 7: Output operator and element access
    String s7("Hello");
    cout << "s7: " << s7 << endl;
    cout << "s7[1]: " << s7[1] << endl;
    cout << "s7[2]: " << s7[2] << endl;

    // Test 8: Append with C-string
    String s8("Asaad");
    cout << "s8 before append: " << s8 << endl;
    s8.append(" Mansour");
    cout << "s8 after append: " << s8 << endl;

    // Test 9: Append with another String
    String s11("Hello");
    String s22(" World");
    s11.append(s22);
    cout << "s11 after appending s22: " << s11 << endl;

    // Test 10: Modifying characters via operator[]
    s11[0] = 'h';
    cout << "s11 after modifying first character: " << s11 << endl;

    // Test 11: Equality operator
    String s121("asaad");
    String s1211("asaad");
    if (s121 == s1211) {
        cout << "s121 is equal to s1211" << endl;
    }
    if (s7 == s11) {
        cout << "s7 is equal to s11" << endl;
    } else {
        cout << "s7 is not equal to s11" << endl;
    }

    // Test 12: Clear
    s121.clear();
    cout << "s121 after clear: \"" << s121 << "\"" << endl;

    // Destructors will be called automatically when objects go out of scope
    return 0;
}
