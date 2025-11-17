// terminal.h
#ifndef TERMINAL_H
#define TERMINAL_H

#ifdef __cplusplus
extern "C" {
#endif

void terminal_move_to(int x, int y);


void terminal_clear(void);

void terminal_set_color(int color);


void terminal_set_colors(int fg_color, int bg_color);

void terminal_reset_color(void);


void terminal_hide_cursor(void);


void terminal_show_cursor(void);


void terminal_get_size(int* width, int* height);

#ifdef __cplusplus
}

void terminal_draw_at(int x, int y, const int val);
void terminal_draw_at(int x, int y, const int val, int n);

#endif

#endif