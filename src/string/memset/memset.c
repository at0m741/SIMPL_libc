#include "ifunc_selector.h"
#include <config.h>

#define memset _memset
#include <string.h>
#undef memset

libft_ifunc_init(_memset, void *, IFUNC_AVX | IFUNC_ERMS, void *, int c, size_t)

libft_weak_alias(memset, _memset)
