#include "screen.h"
#include "terminal.h"
#include "input.h"
#include <stdio.h>
#include <string.h>

// Position constants for screen display
#define SCREEN_TITLE_X      35
#define SCREEN_TITLE_Y      10
#define SCREEN_INFO_Y       20

int screen_show_simple(const char* title) {
    int key;
    int running = 1;
    
    // Clear the screen
    terminal_clear();
    terminal_hide_cursor();
    
    // Display the title in the center
    terminal_move_to(SCREEN_TITLE_X, SCREEN_TITLE_Y);
    printf("%s", title);
    
    // Display instructions at the bottom
    terminal_move_to(10, SCREEN_INFO_Y);
    printf("Press BACKSPACE to go back to menu");
    
    terminal_move_to(10, SCREEN_INFO_Y + 1);
    printf("Press ESC to exit program");
    
    fflush(stdout);
    
    // Wait for user input
    while (running) {
        key = input_get_key();
        
        if (key == KEY_BACKSPACE) {
            // Go back to menu
            return KEY_BACKSPACE;
            
        } else if (key == KEY_ESC) {
            // Exit program
            return KEY_ESC;
        }
    }
    
    return KEY_BACKSPACE;  // Default: go back
}