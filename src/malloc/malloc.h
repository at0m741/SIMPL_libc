#ifndef MALLOC_H
#define MALLOC_H

#include <config.h>

void *malloc(size_t size);
void *posix_memalign(void **memptr, size_t alignment, size_t size);
void *aligned_alloc(size_t alignment, size_t size);

#endif // MALLOC_H
