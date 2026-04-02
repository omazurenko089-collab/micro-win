#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>
#include <stddef.h>

#define KERNEL_VERSION "0.1.0"

void *kmalloc(size_t size);
void kfree(void *ptr);
int create_process(void (*entry_point)(void));
void schedule(void);
void switch_task(void);
void init_interrupts(void);
void enable_interrupts(void);
void disable_interrupts(void);
void kprint(const char *format, ...);
void kprintln(const char *format, ...);

#endif
