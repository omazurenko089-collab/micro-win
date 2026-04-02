#include <stdint.h>

typedef struct {
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
    const char *label;
    void (*on_click)(void);
} button_t;

void button_draw(button_t *b) {
    /* Draw button */
}

void button_click(button_t *b) {
    if (b->on_click) {
        b->on_click();
    }
}
