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



void *_mm_malloc(size_t size, size_t alignment) {
    if (!alignment) {
        alignment = DEFAULT_ALIGNMENT;
    }
	
	/* size_t page_size = get_page_size(); */
	/* if (alignment < page_size) { */
	/* 	alignment = page_size; */
	/* } */
    size_t total_size = size + alignment - 1 + sizeof(void*) + sizeof(size_t);

    void *allocated_mem = _mmap(0, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (allocated_mem == MAP_FAILED) {
        return 0;
    }

    uintptr_t aligned_addr = (uintptr_t)allocated_mem + sizeof(void*) + sizeof(size_t);
    aligned_addr = (aligned_addr + alignment - 1) & ~(alignment - 1);

    ((void**)aligned_addr)[-1] = allocated_mem;
    ((size_t*)aligned_addr)[-2] = total_size;

    return (void*)aligned_addr;
}




