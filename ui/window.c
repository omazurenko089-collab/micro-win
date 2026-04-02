#include <stdint.h>

typedef struct {
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
    const char *title;
} window_t;

void window_draw(window_t *w) {
    /* Draw window on screen */
}

void window_clear(window_t *w) {
    /* Clear window */
}
