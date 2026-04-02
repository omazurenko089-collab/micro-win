#include <stdint.h>

#define VGA_MEMORY 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static uint16_t vga_row = 0;
static uint16_t vga_col = 0;

void vga_clear(void) {
    uint16_t *vga = (uint16_t *)VGA_MEMORY;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vga[i] = 0x0720;
    }
    vga_row = 0;
    vga_col = 0;
}

void vga_write_char(char c) {
    uint16_t *vga = (uint16_t *)VGA_MEMORY;
    uint16_t index = vga_row * VGA_WIDTH + vga_col;
    
    if (c == '\n') {
        vga_row++;
        vga_col = 0;
    } else {
        vga[index] = (0x0F << 8) | (uint8_t)c;
        vga_col++;
    }
    
    if (vga_col >= VGA_WIDTH) {
        vga_col = 0;
        vga_row++;
    }
    
    if (vga_row >= VGA_HEIGHT) {
        vga_clear();
    }
}

void vga_write_string(const char *str) {
    while (*str) {
        vga_write_char(*str++);
    }
}
