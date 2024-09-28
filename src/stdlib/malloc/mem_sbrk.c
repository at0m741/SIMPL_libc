#include "malloc.h"
#include <unistd.h>
int _open(const char *path, int oflag, int mode) {
	int ret;
	asm volatile("int $0x80" : "=a" (ret) : "0" (5), "b" (path), "c" (oflag), "d" (mode));
	return ret;
}

#define SYS_brk 12

void* _sbrk(intptr_t increment) {
    static uintptr_t current_brk = 0;
    uintptr_t new_brk;
    void* result;

    if (current_brk == 0) {
        result = (void*)_syscall(SYS_brk, 0);
        current_brk = (uintptr_t)result;
        if (current_brk == (uintptr_t)-1) {
            return (void*)-1;
        }
    }

    new_brk = current_brk + increment;
    result = (void*)_syscall(SYS_brk, new_brk);
    if ((uintptr_t)result == (uintptr_t)-1) {
        return (void*)-1;
    }

    void* old_brk = (void*)current_brk;
    current_brk = new_brk;

    return old_brk;
}

