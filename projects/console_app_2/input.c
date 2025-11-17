#include "input.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <stdio.h>
#endif

// Platform-specific constants - NO MAGIC NUMBERS!
#ifdef _WIN32
    #define EXTENDED_KEY_PREFIX_1   224
    #define EXTENDED_KEY_PREFIX_2   0
    #define WIN_KEY_UP              72
    #define WIN_KEY_DOWN            80
    #define WIN_KEY_ENTER           13
    #define WIN_KEY_ESC             27
    #define WIN_KEY_BACKSPACE       8
#else
    #define LINUX_KEY_ESC           27
    #define LINUX_KEY_BRACKET       91
    #define LINUX_KEY_UP            65
    #define LINUX_KEY_DOWN          66
    #define LINUX_KEY_ENTER         10
    #define LINUX_KEY_BACKSPACE     127
#endif

int input_getch(void) {
    #ifdef _WIN32
        // Windows: use conio.h getch()
        return getch();
    #else
        // Linux: implement getch() using termios
        struct termios oldattr, newattr;
        int ch;
        
        // Get current terminal attributes
        tcgetattr(STDIN_FILENO, &oldattr);
        
        // Set new attributes: disable canonical mode and echo
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
        
        // Read one character
        ch = getchar();
        
        // Restore old attributes
        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
        
        return ch;
    #endif
}

int input_get_key(void) {
    int first_byte = input_getch();
    
    #ifdef _WIN32
        // ====================================================================
        // WINDOWS: Extended keys come in 2 bytes
        // ====================================================================
        // First byte is 224 or 0 for extended keys (arrows, function keys)
        // Second byte is the actual key code
        
        if (first_byte == EXTENDED_KEY_PREFIX_1 || first_byte == EXTENDED_KEY_PREFIX_2) {
            // This is an extended key - read the second byte
            int second_byte = input_getch();
            
            if (second_byte == WIN_KEY_UP) {
                return KEY_UP;
            } else if (second_byte == WIN_KEY_DOWN) {
                return KEY_DOWN;
            }
        } else if (first_byte == WIN_KEY_ENTER) {
            return KEY_ENTER;
        } else if (first_byte == WIN_KEY_ESC) {
            return KEY_ESC;
        } else if (first_byte == WIN_KEY_BACKSPACE) {
            return KEY_BACKSPACE;
        }
        
    #else
        // ====================================================================
        // LINUX: Extended keys come in 3 bytes (ESC sequences)
        // ====================================================================
        // Arrow keys send: ESC (27) -> '[' (91) -> Letter (65=UP, 66=DOWN)
        
        if (first_byte == LINUX_KEY_ESC) {
            // This might be an ESC sequence - read the second byte
            int second_byte = input_getch();
            
            if (second_byte == LINUX_KEY_BRACKET) {
                // This is an arrow key sequence - read the third byte
                int third_byte = input_getch();
                
                if (third_byte == LINUX_KEY_UP) {
                    return KEY_UP;
                } else if (third_byte == LINUX_KEY_DOWN) {
                    return KEY_DOWN;
                }
            } else {
                // Just ESC key pressed (not followed by '[')
                return KEY_ESC;
            }
        } else if (first_byte == LINUX_KEY_ENTER) {
            return KEY_ENTER;
        } else if (first_byte == LINUX_KEY_BACKSPACE) {
            return KEY_BACKSPACE;
        }
    #endif
    
    // Unknown key
    return KEY_NONE;
}