#ifndef INSTALLER_H
#define INSTALLER_H

#include <stdint.h>

typedef enum {
    LANG_ENGLISH = 0,
    LANG_UKRAINIAN = 1,
    LANG_RUSSIAN = 2
} language_t;

void installer_main(void);
void installer_show_welcome(language_t lang);
int installer_select_language(void);
int installer_select_disk(void);
int installer_confirm_format(void);
void installer_format_disk(void);
void installer_copy_files(void);
void installer_install_bootloader(void);
void installer_reboot(void);

#endif
