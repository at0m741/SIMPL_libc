#ifndef MALLOC_H
#define MALLOC_H

#include <config.h>
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4

#define MAP_PRIVATE 0x02
#define MAP_ANONYMOUS 0x20
#define MAP_FAILED ((void *)-1)

#define MAP_FIXED 0x10

int get_page_size(); 
void *malloc(size_t size);
void *posix_memalign(void **memptr, size_t alignment, size_t size);
void *aligned_alloc(size_t alignment, size_t size);
void* _mmap(void* start, size_t len, int prot, int flags, int fd, size_t offset);
int _munmap(void* addr, size_t length); 

#endif // MALLOC_H
