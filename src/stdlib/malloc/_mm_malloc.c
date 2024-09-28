#include "malloc.h"

#define DEFAULT_ALIGNMENT 16

/* 
 * void *_mm_malloc_t(size_t size, short alignment);
 * 
 * size: size of the memory region to be allocated
 * alignment: alignment of the memory region to be allocated
 * 
 * return value: starting address of the allocated memory region
 * 
 * This function allocates a memory region of size size with alignment alignment.
 * If alignment is 0, the default alignment is used.
 * 
 * If the function fails, it returns 0x0.
 */


