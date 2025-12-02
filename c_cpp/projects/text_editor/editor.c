#include <stdio.h>
#include "editor.h"
#include <stdlib.h>
#include <string.h>
void text_buffer_init(TextBuffer *buffer, int initial_capacity) {
    buffer->lines = malloc(initial_capacity * sizeof(char*));
    buffer->lines[0] = malloc(INITIAL_LINE_LENGTH * (sizeof(char)));
    buffer->lines[0][0] = '\0'; 
    buffer->line_count = 1;
    buffer->line_capacity = initial_capacity;
    buffer->cursor_x = 0;
    buffer->cursor_y = 0;
}
void text_buffer_free(TextBuffer *buffer) {
    for (int i = 0; i < buffer->line_count; i++) {
        free(buffer->lines[i]);
    }
        free(buffer->lines);
}
void text_buffer_save(TextBuffer *buffer, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return; 
    }

    for (int i = 0; i < buffer->line_count; i++) {
        fprintf(file, "%s\n", buffer->lines[i]);
    }

    fclose(file);
}
void buffer_insert_newline(TextBuffer *buffer) {
    if (buffer->line_count >= buffer->line_capacity) {
        buffer->line_capacity *= 2;
        buffer->lines = realloc(buffer->lines, buffer->line_capacity * sizeof(char*));
    }
    buffer->lines[buffer->line_count] = malloc(INITIAL_LINE_LENGTH);
    buffer->lines[buffer->line_count][0] = '\0'; 
    buffer->line_count++;
    buffer->cursor_y++;
    buffer->cursor_x = 0;
}
void buffer_insert_char(TextBuffer *buffer, char c) {
    if (buffer->cursor_x >= 80) {
        buffer_insert_newline(buffer);
    }
    
    char *line = buffer->lines[buffer->cursor_y];
    int len = strlen(line);
    
    memmove(&line[buffer->cursor_x + 1], &line[buffer->cursor_x], len - buffer->cursor_x + 1);
    
    line[buffer->cursor_x] = c;
    buffer->cursor_x++;
}
void buffer_delete_char(TextBuffer *buffer) {
    if (buffer->cursor_x > 0) {
        char *line = buffer->lines[buffer->cursor_y];
        int len = strlen(line);
        memmove(&line[buffer->cursor_x - 1], &line[buffer->cursor_x], len - buffer->cursor_x + 1);
        
        buffer->cursor_x--;
    } else if (buffer->cursor_y > 0) {
        char *current_line = buffer->lines[buffer->cursor_y];
        char *prev_line = buffer->lines[buffer->cursor_y - 1];
        int prev_len = strlen(prev_line);
        int current_len = strlen(current_line);
        
        if (prev_len + current_len < 80) {
            strcat(prev_line, current_line);
            
            free(buffer->lines[buffer->cursor_y]);
            
            for (int i = buffer->cursor_y; i < buffer->line_count - 1; i++) {
                buffer->lines[i] = buffer->lines[i + 1];
            }
            
            buffer->line_count--;
            buffer->cursor_y--;
            buffer->cursor_x = prev_len;
        }
    }
}