#include "../libft.h"


/* check if the vector v contains a zero byte */
/* return 0 if no zero byte is found, otherwise return a non-zero value */
static inline int has_zero_byte(__m256i v) {
    return !_mm256_testz_si256(v, v);
}

/*
** tryin to benchmark Glibc.... but skill issue atm

* usin _mm256_setzero_si256() to create a vector of 32 zero bytes bc assingning a 0 is to lower (yes I know it's a bit overkill)
* usin _mm256_loadu_si256() to load 32 bytes from the memory pointed by ptr in asm :
*                      vpcmpeqb ymm1, ymm0, ymmword ptr [rsi + rcx + 32]

* usin has_zero_byte() to check if the vector v contains a zero byte
__builtin_ctz() is a builtin function that returns the number of trailing 0-bits
*/

size_t ft_strlen(const char *s) {
    const char *ptr = s;
    const __m256i zero = _mm256_setzero_si256();

    /* check if the pointer is aligned on a 32 bytes boundary */
    /* if not, we need to handle the initial bytes separately */
    /*then we need to realign the pointer to 32 bytes boundary*/    
    size_t alignment_offset = (uintptr_t)ptr % AVX2_ALIGNMENT;
    if (alignment_offset != 0) {
        size_t initial_bytes = AVX2_ALIGNMENT - alignment_offset;
        for (size_t i = 0; i < initial_bytes; i++) {
            if (ptr[i] == '\0')
                return i;
        }
        ptr += initial_bytes;
    }
    /*yes I know I'm a bit overkill, but I'm a perfectionist*/
    for (;;) {
        __m256i v = _mm256_loadu_si256((const __m256i *)ptr);
        _mm_prefetch((const char *)(ptr + AVX2_SIZE), _MM_HINT_T0);
        if (has_zero_byte(v)) {
            uint32_t mask = _mm256_movemask_epi8(_mm256_cmpeq_epi8(v, zero));
            return (size_t)(ptr - s) + (size_t)__builtin_ctz(mask);
        }
        ptr += 32;
    }
    return 0; // This line is unreachable but included to prevent compiler warnings
}
