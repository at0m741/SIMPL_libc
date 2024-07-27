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

#define MAX(a, b) ((a) > (b) ? (a) : (b))			  /* return the max value of a and b */
#define PACK_SIZE(size, alloc) ((size) | (alloc))     /* size | alloc, size is the size of the block, alloc is the flag of the block */
#define GET_SIZE(header) ((header) & ~0x7)            /* get the size of the block */
#define GET_ALLOC(header) ((header) & 0x1)            /* get the flag of the block */
#define HDRP(bp) ((char *)(bp) - WSIZE)               /* get the header of the block */
#define MIN_BLOCK_SIZE 16
#define WSIZE 4

#define ALIGNMENT 16
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0xf)
#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))
#define SIZE_T_SIZE_2 (SIZE_T_SIZE << 1)
#define MAX_HEAP_SIZE 1024 * 1024 * 1024
#define PAGE_SIZE 4096


int get_page_size(); 
void *malloc(size_t size);
void *posix_memalign(void **memptr, size_t alignment, size_t size);
void *aligned_alloc(size_t alignment, size_t size);
void* _mmap(void* start, size_t len, int prot, int flags, int fd, size_t offset);
int _munmap(void* addr, size_t length); 

#endif // MALLOC_H
