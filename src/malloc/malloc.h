#ifndef MALLOC_H
#define MALLOC_H

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <immintrin.h>
#include <stdint.h>
#include <string.h>



/*
	* ALIGNMENT: alignment of the block 
	* ALIGN(size, alignment): align the size to the alignment
	* MMAP_THRESHOLD: threshold to use mmap
	* MMAP_SIZE: size of the mmap block
	* MMAP_ALIGN(size): align the size to the mmap size
	* BIN_COUNT: number of bins
	* BIN_MAX_SIZE: maximum size of the bin
	* CACHE_SIZE_L1: size of the L1 cache
	* CACHE_SIZE_L2: size of the L2 cache
*/

#define ALIGNMENT 16
#define ALIGN(size, alignment) (((size) + (alignment - 1)) & ~(alignment - 1))
#define MMAP_THRESHOLD (128 * 1024) 
#define MMAP_SIZE (128 * 1024)
#define MMAP_ALIGN(size) (((size) + (MMAP_SIZE - 1)) & ~(MMAP_SIZE - 1))
#define BIN_COUNT 10
#define BIN_MAX_SIZE 128
#define CACHE_SIZE_L1 32768
#define CACHE_SIZE_L2 262144

/* 
	* get cache level 
	* 0: no cache
	* 1: L1 cache
	* 2: L2 cache
	* 3: L3 cache
	*  this is used to determine the cache size
*/

void get_cache_info();
void *allocate_cache(size_t size);

/*
	* this structure is used to store the block information 
	* size: size of the block
	* next: pointer to the next block
	* free: flag to indicate if the block is free
	* aligned_address: aligned address of the block
	* is_mmap: flag to indicate if the block is allocated using mmap
*/

typedef struct Block {
    size_t size;
    struct Block *next;
    int free;
	void *aligned_address;
	int is_mmap;
} Block;

#define MBLOCK_SIZE ALIGN(sizeof(Block), ALIGNMENT)

/* memory utils */

void *_memcpy_avx(void *dest, const void *src, size_t n);
void *_memset_avx(void *s, int c, size_t n);
void *_memset_ERMS(void *s, int c, size_t n); 
void *_memcpy_ERMS(void *dest, const void *src, size_t n);

/* block utils */

void coalesce_free_blocks(); 
Block *find_free_block(Block **last, size_t size, size_t alignment); 
void split_block(Block *block, size_t size, size_t alignment);

/* memory allocation */

void *request_space_mmap(size_t size, size_t alignment);
Block *request_space_sbrk(Block *last, size_t size, size_t alignment);
void check_alignment(void *aligned_address);
void *_malloc(size_t size);
void *_aligned_alloc(size_t alignment, size_t size);
void _free(void *ptr);

/* memory leak detection and utils */

void check_for_leaks();
/* void hexdump(void *ptr, size_t size); */


void* _mmap(void* start, size_t len, int prot, int flags, int fd, size_t offset); 
int _munmap(void* addr, size_t length); 

void * _sbrk(intptr_t increment);
#endif // MALLOC_H
