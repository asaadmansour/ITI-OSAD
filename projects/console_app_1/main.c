#include "terminal.h"
#include <stdio.h>

int main() {
        terminal_clear();
        terminal_hide_cursor();
        

        terminal_draw_at(10, 5, "Hello at (10, 5)!");
        terminal_draw_at(20, 10, "World at (20, 10)!");

        terminal_set_color(COLOR_GREEN); 

        terminal_draw_at(15, 15, "Colored text!");
        terminal_reset_color();

        terminal_draw_at(30, 8, "+----------+");
        terminal_draw_at(30, 9, "|   Box    |");
        terminal_draw_at(30, 10, "+----------+");
        
        terminal_move_to(0, 22);
        terminal_show_cursor();
        terminal_sleep(3);
        terminal_clear();
    return 0;
}