#include "app.h"
#include <stdio.h>

int main(void) {

    app_init();
    app_run();
    app_shutdown();
    printf("Goodbye!\n");
    
    return 0;
}