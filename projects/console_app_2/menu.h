// menu.h
#ifndef MENU_H
#define MENU_H

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// MENU CONFIGURATION - No Magic Numbers!
// ============================================================================
#define MENU_ITEM_NEW       0
#define MENU_ITEM_DISPLAY   1
#define MENU_ITEM_EXIT      2
#define MENU_ITEM_COUNT     3

#define MENU_START_X        30
#define MENU_START_Y        8
#define MENU_SPACING        4

// ============================================================================
// MENU FUNCTIONS
// ============================================================================

// Draw a single menu item (box with text)
// Parameters:
//   - x, y: position of the top-left corner
//   - text: the text to display inside the box
//   - is_selected: 1 if selected (blue bg), 0 if not (white bg)
void menu_draw_item(int x, int y, const char* text, int is_selected);

// Draw all menu items
// Parameters:
//   - selected_index: which item is currently selected (0, 1, or 2)
void menu_draw_all(int selected_index);

// Run the interactive menu loop
// Returns the index of the selected menu item when Enter is pressed
int menu_run(void);

#ifdef __cplusplus
}
#endif

#endif