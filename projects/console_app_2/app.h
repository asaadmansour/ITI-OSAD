// app.h
#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// APPLICATION STATE - No Magic Numbers!
// ============================================================================
#define APP_STATE_RUNNING       1
#define APP_STATE_EXIT          0

// ============================================================================
// APPLICATION FUNCTIONS
// ============================================================================

// Initialize the application
void app_init(void);

// Run the main application loop
void app_run(void);

// Cleanup and shutdown the application
void app_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif