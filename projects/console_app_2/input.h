// input.h
#ifndef INPUT_H
#define INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// KEY CODES - No Magic Numbers!
// ============================================================================
#define KEY_NONE        0
#define KEY_UP          1
#define KEY_DOWN        2
#define KEY_ENTER       3
#define KEY_ESC         4
#define KEY_BACKSPACE   5

// ============================================================================
// INPUT FUNCTIONS
// ============================================================================

// Read a single character without waiting for Enter
// Returns the raw character code
int input_getch(void);

// Get a key press and return the corresponding KEY_* constant
// Handles extended keys (arrows) across Windows and Linux
int input_get_key(void);

#ifdef __cplusplus
}
#endif

#endif