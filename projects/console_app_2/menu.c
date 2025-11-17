#include "menu.h"
#include "terminal.h"
#include "input.h"
#include <stdio.h>

// Menu item labels - easy to change!
static const char* MENU_LABELS[MENU_ITEM_COUNT] = {
    "|   New    |",
    "| Display  |",
    "|   Exit   |"
};

void menu_draw_item(int x, int y, const char* text, int is_selected) {
    // Set the color based on selection state
    if (is_selected) {
        // Selected: Blue background, Black text
        terminal_set_combined_color(COLOR_BLUE_BG_BLACK_FG);
    } else {
        // Unselected: White background, Black text
        terminal_set_combined_color(COLOR_WHITE_BG_BLACK_FG);
    }
    
    // Draw the box with text
    terminal_draw_at(x, y,     "+----------+");
    terminal_draw_at(x, y + 1, text);
    terminal_draw_at(x, y + 2, "+----------+");
    
    // Reset to default colors
    terminal_reset_color();
}

void menu_draw_all(int selected_index) {
    int i;
    int current_y = MENU_START_Y;
    
    // Draw each menu item
    for (i = 0; i < MENU_ITEM_COUNT; i++) {
        int is_selected = (i == selected_index) ? 1 : 0;
        menu_draw_item(MENU_START_X, current_y, MENU_LABELS[i], is_selected);
        current_y += MENU_SPACING;
    }
}

int menu_run(void) {
    int selected = 0;  // Start with first item selected
    int key;
    int running = 1;
    
    // Clear screen and draw menu
    terminal_clear();
    terminal_hide_cursor();
    menu_draw_all(selected);
    
    // Main menu loop
    while (running) {
        // Get key input
        key = input_get_key();
        
        if (key == KEY_UP) {
            // Move selection up (wrap around to bottom)
            selected--;
            if (selected < 0) {
                selected = MENU_ITEM_COUNT - 1;
            }
            menu_draw_all(selected);
            
        } else if (key == KEY_DOWN) {
            // Move selection down (wrap around to top)
            selected++;
            if (selected >= MENU_ITEM_COUNT) {
                selected = 0;
            }
            menu_draw_all(selected);
            
        } else if (key == KEY_ENTER) {
            // User pressed Enter - return the selected item
            running = 0;
            
        } else if (key == KEY_ESC) {
            // User pressed ESC - return exit option
            return MENU_ITEM_EXIT;
        }
    }
    
    return selected;
}