
/* check if the vector v contains a zero byte */
/* return 0 if no zero byte is found, otherwise return a non-zero value */

/*
** trying to benchmark Glibc.... but skill issue atm

* using _mm256_setzero_si256() to create a vector of 32 zero bytes bc assingning a 0 is to lower (yes I know it's a bit overkill)
* using _mm256_loadu_si256() to load 32 bytes from the memory pointed by ptr in asm :
*                      vpcmpeqb ymm1, ymm0, ymmword ptr [rsi + rcx + 32]

* using has_zero_byte() to check if the vector v contains a zero byte
__builtin_ctz() is a builtin function that returns the number of trailing 0-bits
*/

#include <stdlib.h>
#include <config.h>
#include <immintrin.h>

size_t _strlen_avx(const char *s) 
{
    const char		*ptr = s;
    const __m256i	zero = _mm256_setzero_si256();
    size_t			offset = (uintptr_t)ptr & (VEC_SIZE - 1);
    
	if (offset != 0) 
    {
        size_t align_size = VEC_SIZE - offset;
        __m256i data = _mm256_loadu_si256((const __m256i *)ptr);
        __m256i cmp = _mm256_cmpeq_epi8(data, zero);
        int mask = _mm256_movemask_epi8(cmp);
        if (mask != 0)
        {
            return (size_t)__builtin_ctz(mask);
        }
        ptr += align_size;
    }

	_mm_prefetch(ptr, _MM_HINT_T0);
    while (1) 
    {
        __m256i data = _mm256_loadu_si256((const __m256i *)ptr);
        __m256i cmp = _mm256_cmpeq_epi8(data, zero);
        int mask = _mm256_movemask_epi8(cmp);
        if (mask != 0)
        {
            return (size_t)(ptr - s) + (size_t)__builtin_ctz(mask);
        }
        ptr += VEC_SIZE;
		_mm_prefetch(ptr, _MM_HINT_T0);
		_mm_prefetch(ptr + BLOCK_SIZE, _MM_HINT_T0);
    }

    return 0;
}
