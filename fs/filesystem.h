#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdint.h>
#include <stddef.h>

typedef enum {
    FILE_TYPE_REGULAR = 1,
    FILE_TYPE_DIRECTORY = 2,
    FILE_TYPE_DEVICE = 3
} file_type_t;

typedef struct {
    uint32_t inode_num;
    file_type_t type;
    uint32_t size;
    uint32_t block_count;
    uint32_t created_at;
    uint32_t modified_at;
} inode_t;

int fs_init(void);
int fs_open(const char *path, const char *mode);
int fs_close(int fd);
size_t fs_read(int fd, void *buffer, size_t count);
size_t fs_write(int fd, const void *buffer, size_t count);
int fs_mkdir(const char *path);

#endif
