.PHONY: all clean info run-installer

CC = gcc
ASM = nasm
CFLAGS = -Wall -Wextra -fno-builtin -nostdlib -m32
ASMFLAGS = -f bin

SOURCES = kernel/kernel.c drivers/vga.c drivers/keyboard.c drivers/mouse.c fs/filesystem.c utils/utils.c
INSTALLER_SOURCES = installer/installer.c
BOOT_SOURCE = boot/bootloader.asm

OBJS = $(SOURCES:.c=.o)
INSTALLER_OBJ = installer.o
BOOT_OBJ = boot/bootloader.bin

all: $(BOOT_OBJ) kernel.bin installer

installer: $(INSTALLER_OBJ)
	$(CC) -o installer $(INSTALLER_OBJ)

kernel.bin: $(OBJS)
	$(CC) -o kernel.bin $(CFLAGS) $(OBJS)

$(BOOT_OBJ): $(BOOT_SOURCE)
	$(ASM) $(ASMFLAGS) -o $@ $<

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

run-installer: installer
	./installer

clean:
	rm -f $(OBJS) kernel.bin $(BOOT_OBJ) installer $(INSTALLER_OBJ)

info:
	@echo "micro-win OS Build System"
	@echo "Targets: all, clean, info, run-installer"
