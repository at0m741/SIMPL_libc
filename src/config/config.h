#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "ifunc_selector.h"
#include <sys/stdargs.h>

#if defined(__linux__) && (defined(__GNUC__) || defined(__clang__))
    #define libft_weak_alias(func, func_source) \
        __typeof__(func_source) func __attribute__((weak, alias(#func_source)));
#elif defined(__APPLE__) && defined(__MACH__)
    #define libft_weak_alias(func, func_source) \
        /* Weak alias is not supported on macOS, define an empty macro */
#else
    #define libft_weak_alias(func, func_source) \
        _Pragma("GCC error \"Weak alias is not supported on this compiler\"")
#endif

#define AVX2_ALIGNMENT 32
#define AVX2_SIZE 32
#define BLOCK_SIZE 4096
#define CHAR_PER_VEC (AVX2_SIZE / sizeof(char))
#define VEC_SIZE 32

#endif //__CONFIG_H__

