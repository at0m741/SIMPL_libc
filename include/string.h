#ifndef __STRING_H__
#define __STRING_H__

typedef unsigned long		size_t;

#if defined (__GNUC__) || defined (__clang__)
#	define __nonnull(...) __attribute__ ((__nonnull__ (__VA_ARGS__)))
#else
#	define __nonnull(...)
#endif

#if defined (__GNUC__) || defined (__clang__)
# define __attribute_pure__ __attribute__ ((__pure__))
#else
# define __attribute_pure__ /* Ignore */
#endif

size_t strlen (const char *__s) __attribute_pure__ __nonnull(1);

int strncmp (const char *__s1, const char *__s2, size_t len) __attribute_pure__ __nonnull(1, 2);

void *memset (void *__s, int __c, size_t __n) __nonnull (1);

void *memcpy (void *__d, const void *__s, size_t __n) __nonnull (1, 2);

#endif // __STRING_H__
