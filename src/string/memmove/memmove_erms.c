#include <stdlib.h>

void	*_memmove_erms(void * dest, const void * src, size_t n)
{
	if (__builtin_expect(n == 0, 0) ||\
		__builtin_expect(dest == src, 0) ||\
		__builtin_expect(dest == NULL || src == NULL, 0))
		return dest;
	__asm__ __volatile__(
		"rep movsb"
		: "=D"(dest), "=S"(src), "=c"(n)
		: "0"(dest), "1"(src), "2"(n)
		: "memory"
	);
	return dest;
}
