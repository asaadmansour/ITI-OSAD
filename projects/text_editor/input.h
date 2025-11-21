// input.h
#ifndef INPUT_H
#define INPUT_H
#ifdef __cplusplus
extern "C" {
#endif

#define KEY_NONE        0
#define KEY_UP          1
#define KEY_DOWN        2
#define KEY_ENTER       3
#define KEY_ESC         4
#define KEY_BACKSPACE   5
#define KEY_LEFT        6
#define KEY_RIGHT       7

int input_getch(void);
int input_get_key(void);
#ifdef __cplusplus
}
#endif
#endif