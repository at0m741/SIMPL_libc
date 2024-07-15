#ifndef  __SYS_TYPE_H__
#define __SYS_TYPE_H__

/* Determine architecture width */
#if defined __x86_64__ && !defined __ILP32__
# define __ARCH_WIDTH 64
#else
# define __ARCH_WIDTH 32
#endif

/* Compiler-specific attributes for alignment and inline functions */
#if defined(__clang__) || defined(__GNUC__)
# define _ALIGN(N) __attribute__((aligned(N)))
# define __Inline __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
# define __Inline __forceinline
# define _ALIGN(N)
#else
# define __Inline inline
# define _ALIGN(N)
#endif

/* Define 64-bit integer types based on architecture */
#if __ARCH_WIDTH == 64
typedef unsigned long int __uint64_t;
typedef signed long int __int64_t;
#else
__extension__ typedef unsigned long long int __uint64_t;
__extension__ typedef signed long long int __int64_t;
#endif 

/* Custom unsigned types */
typedef unsigned char			uchar;
typedef unsigned short			ushort;
typedef unsigned int			uint;
typedef unsigned long int		ulong;

/* Custom signed types */
typedef signed char				schar;
typedef signed short			sshort;
typedef signed int				sint;
typedef signed long int			slong;

/* Standard integer types */	
typedef unsigned char			uint8_t;
typedef unsigned short			uint16_t;
typedef unsigned int			uint32_t;
typedef __uint64_t				uint64_t;

typedef signed char				int8_t;
typedef signed short			int16_t;
typedef signed int				int32_t;
typedef __int64_t				int64_t;

/* Floating-point types */
typedef float					float32_t;
typedef double					float64_t;

/* Aligned types */
typedef _ALIGN(8) int8_t		aint8_t;
typedef _ALIGN(8) uint8_t		auint8_t;

typedef _ALIGN(16) int16_t		aint16_t;
typedef _ALIGN(16) uint16_t 	auint16_t;

typedef _ALIGN(32) int32_t		aint32_t;
typedef _ALIGN(32) uint32_t 	auint32_t;
typedef _ALIGN(32) float32_t	afloat32_t;

typedef _ALIGN(64) int64_t		aint64_t;
typedef _ALIGN(64) uint64_t		auint64_t;
typedef _ALIGN(64) float64_t	afloat64_t;

typedef uint32_t __uint32_t;
typedef int32_t __int32_t;

/* Boolean type for C */
#ifndef __cplusplus
typedef _Bool bool;
#define true 1
#define false 0
#endif

#endif // __SYS_TYPE_H__
