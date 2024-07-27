#include "malloc.h"

int get_page_size() {
	int page_size = 0;
	__asm__ __volatile__ (
		".intel_syntax noprefix\n"
		"mov rax, 0x30\n"
		"mov rdi, 0x2\n"
		"syscall\n"
		: "=a"(page_size)
		:
		: "rdi"
	);
	return page_size;
}
