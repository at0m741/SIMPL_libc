#include <config.h>

libft_ifunc_init(_strlen, size_t, IFUNC_AVX, const char *);

libft_weak_alias(ft_strlen, _strlen)
