// terminal.h
#ifndef TERMINAL_H
#define TERMINAL_H

#ifdef __cplusplus
extern "C" {
#endif


#ifdef _WIN32
    #define FG_BLACK            0
    #define FG_DARK_BLUE        1
    #define FG_DARK_GREEN       2
    #define FG_DARK_CYAN        3
    #define FG_DARK_RED         4
    #define FG_DARK_MAGENTA     5
    #define FG_DARK_YELLOW      6
    #define FG_GRAY             7
    #define FG_DARK_GRAY        8
    #define FG_BLUE             9
    #define FG_GREEN            10
    #define FG_CYAN             11
    #define FG_RED              12
    #define FG_MAGENTA          13
    #define FG_YELLOW           14
    #define FG_WHITE            15
#else
    #define FG_BLACK            30
    #define FG_RED              31
    #define FG_GREEN            32
    #define FG_YELLOW           33
    #define FG_BLUE             34
    #define FG_MAGENTA          35
    #define FG_CYAN             36
    #define FG_WHITE            37
    #define FG_BRIGHT_BLACK     90
    #define FG_BRIGHT_RED       91
    #define FG_BRIGHT_GREEN     92
    #define FG_BRIGHT_YELLOW    93
    #define FG_BRIGHT_BLUE      94
    #define FG_BRIGHT_MAGENTA   95
    #define FG_BRIGHT_CYAN      96
    #define FG_BRIGHT_WHITE     97
#endif


#ifdef _WIN32

    #define BG_BLACK            (0 << 4)
    #define BG_DARK_BLUE        (1 << 4)
    #define BG_DARK_GREEN       (2 << 4)
    #define BG_DARK_CYAN        (3 << 4)
    #define BG_DARK_RED         (4 << 4)
    #define BG_DARK_MAGENTA     (5 << 4)
    #define BG_DARK_YELLOW      (6 << 4)
    #define BG_GRAY             (7 << 4)
    #define BG_DARK_GRAY        (8 << 4)
    #define BG_BLUE             (9 << 4)
    #define BG_GREEN            (10 << 4)
    #define BG_CYAN             (11 << 4)
    #define BG_RED              (12 << 4)
    #define BG_MAGENTA          (13 << 4)
    #define BG_YELLOW           (14 << 4)
    #define BG_WHITE            (15 << 4)
#else
    
    #define BG_BLACK            40
    #define BG_RED              41
    #define BG_GREEN            42
    #define BG_YELLOW           43
    #define BG_BLUE             44
    #define BG_MAGENTA          45
    #define BG_CYAN             46
    #define BG_WHITE            47
    #define BG_BRIGHT_BLACK     100
    #define BG_BRIGHT_RED       101
    #define BG_BRIGHT_GREEN     102
    #define BG_BRIGHT_YELLOW    103
    #define BG_BRIGHT_BLUE      104
    #define BG_BRIGHT_MAGENTA   105
    #define BG_BRIGHT_CYAN      106
    #define BG_BRIGHT_WHITE     107
#endif


#ifdef _WIN32

    #define COLOR_WHITE_BG_BLACK_FG     (BG_WHITE | FG_BLACK)
    #define COLOR_BLUE_BG_BLACK_FG      (BG_BLUE | FG_BLACK)
    #define COLOR_DEFAULT               (BG_BLACK | FG_GRAY)
#else
 
    #define COLOR_WHITE_BG_BLACK_FG     1000  
    #define COLOR_BLUE_BG_BLACK_FG      1001  
    #define COLOR_DEFAULT               1002  
#endif


void terminal_move_to(int x, int y);

void terminal_clear(void);

void terminal_set_color(int color);

void terminal_set_colors(int fg_color, int bg_color);

void terminal_set_combined_color(int combined_color);

void terminal_reset_color(void);

void terminal_hide_cursor(void);

void terminal_show_cursor(void);

void terminal_get_size(int* width, int* height);

void terminal_draw_at(int x, int y, const char* text);

#ifdef __cplusplus
}
#endif

#endif