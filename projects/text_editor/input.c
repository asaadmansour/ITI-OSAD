#include "input.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <stdio.h>
#endif

#ifdef _WIN32
    #define EXTENDED_KEY_PREFIX_1   224
    #define EXTENDED_KEY_PREFIX_2   0
    #define WIN_KEY_UP              72
    #define WIN_KEY_DOWN            80
    #define WIN_KEY_LEFT            75
    #define WIN_KEY_RIGHT           77
    #define WIN_KEY_ENTER           13
    #define WIN_KEY_ESC             27
    #define WIN_KEY_BACKSPACE       8
#else
    #define LINUX_KEY_ESC           27
    #define LINUX_KEY_BRACKET       91
    #define LINUX_KEY_UP            65
    #define LINUX_KEY_DOWN          66
    #define LINUX_KEY_RIGHT         67
    #define LINUX_KEY_LEFT          68
    #define LINUX_KEY_ENTER         10
    #define LINUX_KEY_BACKSPACE     127
#endif

int input_getch(void) {
    #ifdef _WIN32
        return getch();
    #else
        struct termios oldattr, newattr;
        int ch;
        tcgetattr(STDIN_FILENO, &oldattr);
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
        
        return ch;
    #endif
}

int input_get_key(void) {
    int first_byte = input_getch();
    
    #ifdef _WIN32
        
        if (first_byte == EXTENDED_KEY_PREFIX_1 || first_byte == EXTENDED_KEY_PREFIX_2) {
            int second_byte = input_getch();
            
            if (second_byte == WIN_KEY_UP) {
                return KEY_UP;
            } else if (second_byte == WIN_KEY_DOWN) {
                return KEY_DOWN;
            } else if (second_byte == WIN_KEY_LEFT) {
                return KEY_LEFT;
            } else if (second_byte == WIN_KEY_RIGHT) {
                return KEY_RIGHT;
            }
        } else if (first_byte == WIN_KEY_ENTER) {
            return KEY_ENTER;
        } else if (first_byte == WIN_KEY_ESC) {
            return KEY_ESC;
        } else if (first_byte == WIN_KEY_BACKSPACE) {
            return KEY_BACKSPACE;
        }
        
    #else
        if (first_byte == LINUX_KEY_ESC) {
            int second_byte = input_getch();
            if (second_byte == LINUX_KEY_BRACKET) {
                int third_byte = input_getch();
                if (third_byte == LINUX_KEY_UP) {
                    return KEY_UP;
                } else if (third_byte == LINUX_KEY_DOWN) {
                    return KEY_DOWN;
                } else if(third_byte == LINUX_KEY_LEFT) {
                    return KEY_LEFT;
                } else if (third_byte == LINUX_KEY_RIGHT) {
                    return KEY_RIGHT;
                }
            } else {
                return KEY_ESC;
            }
        } else if (first_byte == LINUX_KEY_ENTER) {
            return KEY_ENTER;
        } else if (first_byte == LINUX_KEY_BACKSPACE) {
            return KEY_BACKSPACE;
        }
    #endif
    return first_byte;
}