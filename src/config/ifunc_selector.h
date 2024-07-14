#ifndef __IFUNC_SELECTOR_H__
# define __IFUNC_SELECTOR_H__

#include "cpuid_conf.h"

enum ifunc_type_u {
  IFUNC_MMX = 1u,
  IFUNC_SSE = (1u << 1),
  IFUNC_AVX = (1u << 2),
  IFUNC_ERMS = (1u << 3),
};

#ifdef VERBOSE
# define IFUNC_LOG(func) printf("ifunc %s is selected\n", #func);
#else
# define IFUNC_LOG(func)
#endif

#define _func_selected(func)                                                   \
  IFUNC_LOG(func)                                                              \
  return func;

#define __ifunc_create_prototype(name, type_name, ...)                         \
  type_name name##_ERMS(__VA_ARGS__);                                          \
  type_name name##_AVX(__VA_ARGS__);                                           \
  type_name name##_SSE(__VA_ARGS__);                                           \
  type_name name##_BASE(__VA_ARGS__);

#define __ifunc_creator(name, type_name, version, ...)                         \
	type_name (*name##_ifunc())(__VA_ARGS__) {                                 \
    if ((version & IFUNC_ERMS) && simd_support.erms) {                         \
      _func_selected(name##_ERMS)                                              \
    }                                                                          \
    if ((version & IFUNC_AVX) && simd_support.avx) {                           \
      _func_selected(name##_AVX);                                              \
    }                                                                          \
    if ((version & IFUNC_SSE) && simd_support.sse) {                           \
      _func_selected(name##_SSE);                                              \
    }                                                                          \
    _func_selected(name##_BASE);                                               \
  }

#define libft_ifunc_init(name, type_name, version, ...)                        \
  extern type_name name(__VA_ARGS__) __attribute__((ifunc(#name "_ifunc")));   \
  __ifunc_create_prototype(name, type_name, __VA_ARGS__)                       \
  __ifunc_creator(name, type_name, version, __VA_ARGS__)

#endif
