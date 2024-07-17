#include <config.h>

#define strlen _strlen
#include <string.h>
#undef strlen

libft_ifunc_init(_strlen, size_t, IFUNC_AVX | IFUNC_SSE, const char *)

libft_weak_alias(strlen, _strlen)
