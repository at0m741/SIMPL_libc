#ifndef __STDINT_H__
#define __STDINT_H__

#include "sys/types.h"

/* Fast types.  */
typedef int8_t		int_fast8_t;
typedef int8_t		int_least8_t;
typedef uint8_t		uint_fast8_t;
typedef uint8_t		uint_least8_t;

typedef int16_t		int_fast16_t;
typedef int16_t		int_least16_t;
typedef uint16_t	uint_fast16_t;
typedef uint16_t	uint_least16_t;
typedef int32_t		int_fast32_t;
typedef int32_t		int_least32_t;
typedef uint32_t	uint_fast32_t;
typedef uint32_t	uint_least32_t;

typedef int64_t 	int_least64_t;
typedef int64_t		int_fast64_t;
typedef uint64_t	uint_fast64_t;
typedef uint64_t 	uint_least64_t;


/* Types for `void *' pointers.  */
#if __ARCH_WIDTH == 64
typedef long int			intptr_t;
typedef unsigned long int	uintptr_t;
#else
typedef int					intptr_t;
typedef unsigned int		uintptr_t;
#endif

/* Macros for minimum-width integer constants */
# if __ARCH_WIDTH == 64
#  define __INT64_C(c)	c ## L
#  define __UINT64_C(c)	c ## UL
# else
#  define __INT64_C(c)	c ## LL
#  define __UINT64_C(c)	c ## ULL
# endif

/* Limits of specified-width integer types */
#define INT8_MIN   (-0x7f - 1)
#define INT16_MIN  (-0x7fff - 1)
#define INT32_MIN  (-0x7fffffff - 1)
#define INT64_MIN  (-__INT64_C(0x7fffffffffffffff) - 1)

#define INT8_MAX   (0x7f)
#define INT16_MAX  (0x7fff)
#define INT32_MAX  (0x7fffffff)
#define INT64_MAX  (__INT64_C(0x7fffffffffffffff))

#define UINT8_MAX  (0xff)
#define UINT16_MAX (0xffff)
#define UINT32_MAX (0xffffffffu)
#define UINT64_MAX (__UINT64_C(0xffffffffffffffff))

/* Limits of standard integer types */
#define CHAR_MIN    INT8_MIN
#define CHAR_MAX    INT8_MAX
#define UCHAR_MAX   UINT8_MAX

#define SHRT_MIN    INT16_MIN
#define SHRT_MAX    INT16_MAX
#define USHRT_MAX   UINT16_MAX

#define INT_MIN     INT32_MIN
#define INT_MAX     INT32_MAX
#define UINT_MAX    UINT32_MAX

/* Limits of long types */
#define LONG_MIN    INT64_MIN
#define LONG_MAX    INT64_MAX
#define ULONG_MAX   UINT64_MAX

/* Limits of long long types */
#define LLONG_MIN   INT64_MIN
#define LLONG_MAX   INT64_MAX
#define ULLONG_MAX  UINT64_MAX

#endif // __STDINT_H__
