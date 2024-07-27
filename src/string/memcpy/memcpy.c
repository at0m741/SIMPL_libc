#include "ifunc_selector.h"
#include <config.h>

#define memcpy _memcpy
#include <string.h>
#undef memcpy

libft_ifunc_init(_memcpy, void *, IFUNC_AVX, void *, const void *, size_t)

libft_weak_alias(memcpy, _memcpy)
