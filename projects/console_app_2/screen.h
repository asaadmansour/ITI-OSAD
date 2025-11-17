// screen.h
#ifndef SCREEN_H
#define SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// SCREEN TYPES - No Magic Numbers!
// ============================================================================
#define SCREEN_MENU         0
#define SCREEN_NEW          1
#define SCREEN_DISPLAY      2
#define SCREEN_EXIT         3

// ============================================================================
// SCREEN FUNCTIONS
// ============================================================================

// Display a simple screen with a title
// Shows the title in the center and waits for Backspace or ESC
// Returns: KEY_BACKSPACE (go back to menu) or KEY_ESC (exit program)
int screen_show_simple(const char* title);

#ifdef __cplusplus
}
#endif

#endif