#include "malloc.h"

static char *heap = 0;
static char *mem_brk = 0;
static char *mem_max_addr = 0;

int _open(const char *path, int oflag, int mode) {
	int ret;
	asm volatile("int $0x80" : "=a" (ret) : "0" (5), "b" (path), "c" (oflag), "d" (mode));
	return ret;
}

void init_memory(void) {
	int device_zero = _open("/dev/zero", 0, 0);
	heap = _mmap((void *)0x800000000, 
						MAX_HEAP_SIZE, 
						PROT_READ		| PROT_WRITE, 
						MAP_PRIVATE	| MAP_ANONYMOUS, 
						device_zero, 0);
	mem_max_addr = heap + MAX_HEAP_SIZE;
	mem_brk = heap;
}

void mem_deinit(void) {
	_munmap(heap, MAX_HEAP_SIZE);
}

void *mem_sbrk(size_t incr) {
	char *old_brk = mem_brk;
	
	if ((incr < 0) || (mem_brk + incr) > mem_max_addr) {
		printf("ERROR: mem_sbrk failed. home run !\n");
		return (void *) -1;
	}

	mem_brk += incr;
	return (void *)old_brk;
}

void *mem_heap_lo(void) {
	return (void *)heap;
}

void *mem_heap_hi(void) {
	return (void *)(mem_brk - 1);
}

size_t mem_heapsize(void) {
	return (size_t)((void *)mem_brk - (void *)heap);
}

size_t mem_pagesize(void) {
	return (size_t)get_page_size();
}
