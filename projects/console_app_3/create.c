#include "create.h"
#include "terminal.h"
#include "input.h"
#include <stdio.h>

static FormData users[MAX_USERS];  
static int user_count = 0;

void creator_init(void) {
    user_count = 0;
}

int creator_add_user(void) {
    terminal_clear();
    terminal_show_cursor();
    
    if (user_count >= MAX_USERS) {
        printf("\n User limit reached! Press any key to continue...\n");
        input_getch();
        return 0;
    }

    printf("\n === ADD NEW USER ===\n\n");
    
    FormData data = form_data_create();
    int is_valid = form_data_input(&data);

    if (is_valid == 0) {
        printf("\n Invalid input! Press any key to continue...\n");
        input_getch();
        return 0;
    }

    users[user_count++] = data;
    printf("\n User added successfully! Press any key to continue...\n");
    input_getch();
    return 1;
}

void creator_display_users(void) {
    terminal_clear();
    terminal_show_cursor();
    
    printf("\n === USER LIST ===\n\n");
    
    if (user_count == 0) {
        printf(" No users to display.\n");
    } else {
        for (int i = 0; i < user_count; i++) {
            printf(" User %d:\n", i + 1);
            printf(" ------------------\n");
            form_data_print(&users[i]);
            printf(" ------------------\n\n");
        }
    }
    
    printf("\n Press any key to return to menu...\n");
    input_getch();
}
