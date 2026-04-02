#include "kernel.h"

static uint8_t heap[4096];
static size_t heap_ptr = 0;

void *kmalloc(size_t size) {
    if (heap_ptr + size > sizeof(heap)) return NULL;
    void *ptr = &heap[heap_ptr];
    heap_ptr += size;
    return ptr;
}

void kfree(void *ptr) { (void)ptr; }

int create_process(void (*entry_point)(void)) {
    if (entry_point == NULL) return -1;
    return 0;
}

void schedule(void) { }
void switch_task(void) { }
void init_interrupts(void) { }
void enable_interrupts(void) { __asm__("sti"); }
void disable_interrupts(void) { __asm__("cli"); }

void kprint(const char *format, ...) { (void)format; }
void kprintln(const char *format, ...) { (void)format; }

void kernel_main(void) {
    kprintln("micro-win OS Kernel v%s", KERNEL_VERSION);
    while (1) schedule();
}
