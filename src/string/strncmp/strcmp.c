#include "ifunc_selector.h"
#include <config.h>

#define strncmp _strncmp
#include <string.h>
#undef strncmp

libft_ifunc_init(_strncmp, int, IFUNC_AVX, const char *, const char *, size_t)  

libft_weak_alias(strncmp, _strncmp)
