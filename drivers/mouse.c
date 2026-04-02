#include <stdint.h>

#define MOUSE_DATA_PORT 0x60
#define MOUSE_STATUS_PORT 0x64
#define MOUSE_CMD_PORT 0x64

typedef struct {
    int8_t x;
    int8_t y;
    uint8_t buttons;
} mouse_packet_t;

static mouse_packet_t current_packet;

void mouse_init(void) {
    /* Enable mouse */
}

void mouse_get_packet(mouse_packet_t *packet) {
    if (packet) {
        packet->x = current_packet.x;
        packet->y = current_packet.y;
        packet->buttons = current_packet.buttons;
    }
}
