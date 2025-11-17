#ifndef TERMINAL_H
#define TERMINAL_H

#ifdef __cplusplus
extern "C" {
#endif


#ifdef _WIN32
    #include <windows.h>
    #define COLOR_BLACK         0
    #define COLOR_DARK_BLUE     1
    #define COLOR_DARK_GREEN    2
    #define COLOR_DARK_CYAN     3
    #define COLOR_DARK_RED      4
    #define COLOR_DARK_MAGENTA  5
    #define COLOR_DARK_YELLOW   6
    #define COLOR_GRAY          7
    #define COLOR_DARK_GRAY     8
    #define COLOR_BLUE          9
    #define COLOR_GREEN         10
    #define COLOR_CYAN          11
    #define COLOR_RED           12
    #define COLOR_MAGENTA       13
    #define COLOR_YELLOW        14
    #define COLOR_WHITE         15
#else
    #include <unistd.h>
    #define COLOR_BLACK         30
    #define COLOR_RED           31
    #define COLOR_GREEN         32
    #define COLOR_YELLOW        33
    #define COLOR_BLUE          34
    #define COLOR_MAGENTA       35
    #define COLOR_CYAN          36
    #define COLOR_WHITE         37
#endif


#ifdef _WIN32
    #define COLOR_DEFAULT COLOR_GRAY
#else
    #define COLOR_DEFAULT COLOR_WHITE
#endif

void terminal_move_to(int x, int y);
void terminal_clear(void);
void terminal_set_color(int color);
void terminal_reset_color(void);
void terminal_hide_cursor(void);
void terminal_show_cursor(void);
void terminal_draw_at(int x, int y, const char* text);
void terminal_sleep(int seconds);
#ifdef __cplusplus
}
#endif

#endif
