#include <config.h>

#define strncmp _strncmp
#include <string.h>
#undef strncmp

simpl_func_ifunc_init(_strncmp, int, IFUNC_AVX, const char *, const char *, size_t)  

simpl_weak_alias(strncmp, _strncmp)
