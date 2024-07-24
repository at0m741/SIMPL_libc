#include "malloc.h"
#include <config.h>

void * _mmap(void *start, size_t len, int prot, int flag, int fd, off_t offset) {
	if (!start || !len || !prot) {return;}
	return (void *)syscall(SYS_mmap, start, len, prot, flag, fd, offset);
}

