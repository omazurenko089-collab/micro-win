#include <stdint.h>

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

static char keymap[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8',
    '9', '0', '-', '=', '\b', '\t',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
    '[', ']', '\n', 0,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
    '\'', '`', 0, '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0, '*', 0, ' '
};

uint8_t keyboard_read_scancode(void) {
    return *((uint8_t *)KEYBOARD_DATA_PORT);
}

char keyboard_scancode_to_char(uint8_t scancode) {
    if (scancode > 127) return 0;
    return keymap[scancode];
}
