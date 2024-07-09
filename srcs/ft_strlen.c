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
#define SMALL_STRING_THRESHOLD 16
#define VEC_SIZE 32
#define AVX2_SIZE 32
#define BLOCK_SIZE 4096
#define PAGE_SIZE 4096
size_t ft_strlen(const char *s) 
{
    const char *ptr = s;
    const __m256i zero = _mm256_setzero_si256();
	/*test if s is NULL*/
	if (__builtin_expect(!s, 0))
		return 0;
	
	/*handle small strings*/
   __m256i zero_mask = _mm256_setzero_si256();

    _mm_prefetch(ptr, _MM_HINT_NTA);
    _mm_prefetch(ptr + PAGE_SIZE, _MM_HINT_NTA);
    size_t offset = (uintptr_t)ptr & (VEC_SIZE - 1);

    if (offset) 
    {
        size_t align_size = VEC_SIZE - offset;
        __m256i data = _mm256_loadu_si256((__m256i*)ptr);
        __m256i cmp = _mm256_cmpeq_epi8(data, zero_mask);
        int mask = _mm256_movemask_epi8(cmp);
        _mm_prefetch(ptr + align_size, _MM_HINT_NTA);
        _mm_prefetch(ptr + align_size + PAGE_SIZE, _MM_HINT_NTA);

        if (mask)
            return ptr - s + __builtin_ctz(mask);
        
        ptr += align_size;
    }

    /* check if the pointer is aligned on a 32 bytes boundary */
    /* if not, we need to handle the initial bytes separately */
    /*then we need to realign the pointer to 32 bytes boundary*/    
    size_t alignment_offset = (uintptr_t)ptr % AVX2_ALIGNMENT;
    if (alignment_offset != 0) 
    {
		/*realignment*/
		/* then use simd to check for zero bytes */

        size_t initial_bytes = AVX2_ALIGNMENT - alignment_offset;
        for (size_t i = 0; i < initial_bytes; i++) 
            if (ptr[i] == '\0') 
				return (ptr - s) + i;
        ptr += initial_bytes;
    }
    /*yes I know I'm a bit overkill, but I'm a perfectionist*/
    for (;;) 
    {
        __m256i v = _mm256_loadu_si256((const __m256i *)ptr);
        if (has_zero_byte(v)) 
        {
            uint32_t mask = _mm256_movemask_epi8(_mm256_cmpeq_epi8(v, zero));
            return (size_t)(ptr - s) + (size_t)__builtin_ctz(mask);
        }
        ptr += 32;
    }
	
	/*handle crossing the 4096 bytes boundary*/
	if (((uintptr_t)ptr & (BLOCK_SIZE - 1)) < AVX2_SIZE) 
	{
		__builtin_prefetch(ptr, 0, 3);
		__builtin_prefetch(ptr + 32, 0, 3);
			for (size_t i = 0; i < AVX2_SIZE; i++)
			if (ptr[i] == '\0')
				return (ptr - s) + i;
	}
    return 0; // This line is unreachable but included to prevent compiler warnings
}
