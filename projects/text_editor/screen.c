#include "screen.h"
#include "terminal.h"
#include "editor.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#define SCREEN_TITLE_X      35
#define SCREEN_TITLE_Y      10
#define SCREEN_INFO_Y       20

int screen_show_simple(const char* title) {
    int key;
    int running = 1;
    
    terminal_clear();
    terminal_hide_cursor();
    
    terminal_move_to(SCREEN_TITLE_X, SCREEN_TITLE_Y);
    printf("%s", title);
    
    terminal_move_to(10, SCREEN_INFO_Y);
    printf("Press BACKSPACE to go back to menu");
    
    terminal_move_to(10, SCREEN_INFO_Y + 1);
    printf("Press ESC to exit program");
    
    fflush(stdout);

    while (running) {
        key = input_get_key();
        
        if (key == KEY_BACKSPACE) {
            return KEY_BACKSPACE;
            
        } else if (key == KEY_ESC) {
            return KEY_ESC;
        }
    }
    
    return KEY_BACKSPACE;  
}
    int screen_show_editor() {
        int key;
        int running = 1;
        TextBuffer buffer;
        text_buffer_init(&buffer,16);
        while(running) {
            terminal_clear();
            for(int i=0;i<buffer.line_count;i++) {
                terminal_move_to(0,i);
                printf("%s", buffer.lines[i]);
            }
            terminal_move_to(buffer.cursor_x, buffer.cursor_y);
            terminal_show_cursor();
            fflush(stdout);
            key = input_get_key();
            if(key == KEY_UP) {
                if(buffer.cursor_y>0) {
                    buffer.cursor_y--;
                    int len = strlen(buffer.lines[buffer.cursor_y]);
                    if (buffer.cursor_x > len) buffer.cursor_x = len;
                }
            }   
            else if (key == KEY_DOWN) {
                if (buffer.cursor_y < buffer.line_count - 1) {
                    buffer.cursor_y++;
                    int len = strlen(buffer.lines[buffer.cursor_y]);
                    if (buffer.cursor_x > len) buffer.cursor_x = len;
                }
            }   
            else if (key == KEY_LEFT) {
                if (buffer.cursor_x > 0) buffer.cursor_x--;
            }   
            else if (key == KEY_RIGHT) {
                int len = strlen(buffer.lines[buffer.cursor_y]);
                if (buffer.cursor_x < len && buffer.cursor_x < 80) {
                buffer.cursor_x++;
                }
            } 
            else if(key == KEY_ENTER) {
                buffer_insert_newline(&buffer);
            }
            else if (key == KEY_ESC) {
                running = 0;
            } else if(key == KEY_BACKSPACE) {
                buffer_delete_char(&buffer);
            }
            else if (key >= 32 && key <= 126) { 
                buffer_insert_char(&buffer, (char)key);
            }
        }
        
    }