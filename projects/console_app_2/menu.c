#include "menu.h"
#include "terminal.h"
#include "input.h"
#include <stdio.h>

static const char* MENU_LABELS[MENU_ITEM_COUNT] = {
    "|   New    |",
    "| Display  |",
    "|   Exit   |"
};

void menu_draw_item(int x, int y, const char* text, int is_selected) {
    if (is_selected) {
        terminal_set_combined_color(COLOR_BLUE_BG_BLACK_FG);
    } else {
        terminal_set_combined_color(COLOR_WHITE_BG_BLACK_FG);
    }
    
    terminal_draw_at(x, y,     "+----------+");
    terminal_draw_at(x, y + 1, text);
    terminal_draw_at(x, y + 2, "+----------+");
    terminal_reset_color();
}

void menu_draw_all(int selected_index) {
    int i;
    int current_y = MENU_START_Y;
    

    for (i = 0; i < MENU_ITEM_COUNT; i++) {
        int is_selected = (i == selected_index) ? 1 : 0;
        menu_draw_item(MENU_START_X, current_y, MENU_LABELS[i], is_selected);
        current_y += MENU_SPACING;
    }
}

int menu_run(void) {
    int selected = 0; 
    int key;
    int running = 1;
    terminal_clear();
    terminal_hide_cursor();
    menu_draw_all(selected);

    while (running) {
        key = input_get_key();
        
        if (key == KEY_UP) {
            selected--;
            if (selected < 0) {
                selected = MENU_ITEM_COUNT - 1;
            }
            menu_draw_all(selected);
            
        } else if (key == KEY_DOWN) {
            selected++;
            if (selected >= MENU_ITEM_COUNT) {
                selected = 0;
            }
            menu_draw_all(selected);
            
        } else if (key == KEY_ENTER) {
            running = 0;
            
        } else if (key == KEY_ESC) {
            return MENU_ITEM_EXIT;
        }
    }
    
    return selected;
}