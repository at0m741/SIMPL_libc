#include <config.h>

#define memset _memset
#include <string.h>
#undef memset

libft_ifunc_init(_memset, void *, IFUNC_AVX | IFUNC_ERMS, void *src, int c, size_t len)

libft_weak_alias(memset, _memset)
