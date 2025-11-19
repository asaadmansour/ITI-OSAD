// app.h
#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

#define APP_STATE_RUNNING       1
#define APP_STATE_EXIT          0

// ============================================================================
// APPLICATION FUNCTIONS
// ============================================================================
void app_init(void);
void app_run(void);
void app_shutdown(void);
#ifdef __cplusplus
}
#endif

#endif