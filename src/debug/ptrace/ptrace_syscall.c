#include "../includes/ptrace.h"

long _ptrace(int request, int pid, void *addr, void *data) {
	long ret;
	__asm__ __volatile__ (
		".intel_syntax noprefix\n"
		"mov rax, 0x101\n"
		"syscall\n"
		: "=a"(ret)
		: "D"(request), "S"(pid), "d"(addr), "r"(data)
		: "memory"
	);
	return ret;
}

void ptrace_init(void) {
	_ptrace(0x101, 0, 0, 0);
}

void ptrace_deinit(void) {
	_ptrace(0x102, 0, 0, 0);
}




		
