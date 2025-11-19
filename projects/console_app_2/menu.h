// menu.h
#ifndef MENU_H
#define MENU_H

#ifdef __cplusplus
extern "C" {
#endif

#define MENU_ITEM_NEW       0
#define MENU_ITEM_DISPLAY   1
#define MENU_ITEM_EXIT      2
#define MENU_ITEM_COUNT     3

#define MENU_START_X        30
#define MENU_START_Y        8
#define MENU_SPACING        4


void menu_draw_item(int x, int y, const char* text, int is_selected);

void menu_draw_all(int selected_index);

int menu_run(void);

#ifdef __cplusplus
}
#endif

#endif