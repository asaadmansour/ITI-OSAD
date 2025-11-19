// screen.h
#ifndef SCREEN_H
#define SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif


#define SCREEN_MENU         0
#define SCREEN_NEW          1
#define SCREEN_DISPLAY      2
#define SCREEN_EXIT         3

int screen_show_simple(const char* title);

#ifdef __cplusplus
}
#endif

#endif