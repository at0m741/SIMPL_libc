#include <config.h>

#define memcpy _memcpy
#include <string.h>
#undef memcpy

simpl_func_ifunc_init(_memcpy, void *, IFUNC_AVX, void *, const void *, size_t)

simpl_weak_alias(memcpy, _memcpy)
