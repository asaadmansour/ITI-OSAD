#define INITIAL_LINE_LENGTH 128
typedef struct TextBuffer {
    char ** lines;
    int line_count;
    int line_capacity;
    int cursor_x;
    int cursor_y;
} TextBuffer;
void text_buffer_init(TextBuffer *buffer, int capacity);
void buffer_insert_newline(TextBuffer *buffer);
void buffer_insert_char(TextBuffer *buffer, char c);
void buffer_delete_char(TextBuffer *buffer);
void text_buffer_free();