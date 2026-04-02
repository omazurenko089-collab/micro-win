#include "installer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *strings[3][10] = {
    /* English */
    {
        "micro-win OS Installer",
        "Select Language",
        "Select Disk",
        "Confirm Format",
        "Formatting Disk",
        "Copying Files",
        "Installing Bootloader",
        "Rebooting System",
        "Installation Complete",
        "Installation Failed"
    },
    /* Українська */
    {
        "Установщик micro-win OS",
        "Виберіть мову",
        "Виберіть диск",
        "Підтвердіть форматування",
        "Форматування диска",
        "Копіювання файлів",
        "Встановлення завантажувача",
        "Перезавантаження системи",
        "Установка завершена",
        "Установка не вдалася"
    },
    /* Русский */
    {
        "Установщик micro-win OS",
        "Выберите язык",
        "Выберите диск",
        "Подтвердите форматирование",
        "Форматирование диска",
        "Копирование файлов",
        "Установка загрузчика",
        "Перезагрузка системы",
        "Установка завершена",
        "Установка не удалась"
    }
};

language_t current_language = LANG_ENGLISH;

void installer_main(void) {
    printf("\n=== %s ===\n\n", strings[current_language][0]);
    
    current_language = installer_select_language();
    int disk = installer_select_disk();
    
    if (installer_confirm_format()) {
        installer_format_disk();
        installer_copy_files();
        installer_install_bootloader();
        printf("\n%s\n", strings[current_language][8]);
        installer_reboot();
    } else {
        printf("%s\n", strings[current_language][9]);
    }
}

int installer_select_language(void) {
    printf("%s:\n", strings[LANG_ENGLISH][1]);
    printf("1. English\n");
    printf("2. Українська\n");
    printf("3. Русский\n");
    printf("Select (1-3): ");
    
    int choice;
    scanf("%d", &choice);
    return (choice - 1) % 3;
}

int installer_select_disk(void) {
    printf("\n%s:\n", strings[current_language][2]);
    printf("1. C:\\\n");
    printf("2. D:\\\n");
    printf("3. E:\\\n");
    printf("Select (1-3): ");
    
    int choice;
    scanf("%d", &choice);
    return choice;
}

int installer_confirm_format(void) {
    printf("\n%s? (y/n): ", strings[current_language][3]);
    char c;
    scanf("%c", &c);
    return c == 'y' || c == 'Y';
}

void installer_format_disk(void) {
    printf("\n%s...\n", strings[current_language][4]);
    for (int i = 0; i <= 100; i += 10) {
        printf("[");
        for (int j = 0; j < i / 5; j++) printf("=");
        printf("> %d%%\n", i);
    }
}

void installer_copy_files(void) {
    printf("%s...\n", strings[current_language][5]);
    for (int i = 0; i <= 100; i += 25) {
        printf("Progress: %d%%\n", i);
    }
}

void installer_install_bootloader(void) {
    printf("%s...\n", strings[current_language][6]);
}

void installer_reboot(void) {
    printf("\n%s за 5 сек...\n", strings[current_language][7]);
    for (int i = 5; i > 0; i--) {
        printf("%d...\n", i);
    }
}
