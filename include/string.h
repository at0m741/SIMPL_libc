#ifndef __STRING_H__
#define __STRING_H__

typedef unsigned long		size_t;

#if defined (__GNUC__) || defined (__clang__)
#	define __nonnull(params) __attribute__ ((__nonnull__ (params)))
#else
#	define __nonnull(params)
#endif

#if defined (__GNUC__) || defined (__clang__)
# define __attribute_pure__ __attribute__ ((__pure__))
#else
# define __attribute_pure__ /* Ignore */
#endif

size_t strlen (const char *__s) __attribute_pure__ __nonnull(1);

extern void *memset (void *__s, int __c, size_t __n) __nonnull ((1));

#endif // __STRING_H__
