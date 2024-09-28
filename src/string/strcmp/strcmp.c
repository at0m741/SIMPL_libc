#include <config.h>

#define strcmp _strcmp
#include <string.h>
#undef strcmp

simpl_func_ifunc_init(_strcmp, int, IFUNC_AVX | IFUNC_SSE, const char *, const char *)

simpl_weak_alias(strcmp, _strcmp)
