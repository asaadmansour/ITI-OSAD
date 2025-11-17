#include "terminal.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

void terminal_move_to(int x, int y) {
    #ifdef _WIN32
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #else
        printf("\033[%d;%dH", y + 1, x + 1);
        fflush(stdout);
    #endif
}

void terminal_clear(void) {
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033[2J\033[1;1H");
        fflush(stdout);
    #endif
}

void terminal_set_color(int color) {
    #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    #else
        printf("\033[%dm", color);
        fflush(stdout);
    #endif
}

void terminal_reset_color(void) {
    #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    #else
        printf("\033[0m");
        fflush(stdout);
    #endif
}

void terminal_hide_cursor(void) {
    #ifdef _WIN32
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    #else
        printf("\033[?25l");
        fflush(stdout);
    #endif
}

void terminal_show_cursor(void) {
    #ifdef _WIN32
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = TRUE;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    #else
        printf("\033[?25h");
        fflush(stdout);
    #endif
}
void terminal_draw_at(int x, int y, const char* text) {
    terminal_move_to(x, y);
    printf("%s", text);
    fflush(stdout);
}
void terminal_sleep(int seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000);
    #else
        sleep(seconds);
    #endif
}