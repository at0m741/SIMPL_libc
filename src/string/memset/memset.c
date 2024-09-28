#include "func_ifunc_selector.h"
#include <config.h>

#define memset _memset
#include <string.h>
#undef memset

simpl_func_ifunc_init(_memset, void *, IFUNC_AVX | IFUNC_ERMS, void *, int c, size_t)

simpl_weak_alias(memset, _memset)
