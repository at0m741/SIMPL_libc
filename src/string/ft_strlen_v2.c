/*
 *  this is the second implementation of the strlen function using AVX2 instructions
 *  less instruction, less cache misses, less branch mispredictions
 *  this implementation is faster than the first one but handle less cases 
*/

/*
 *  Explanation:
 *  The function uses AVX2 instructions to find the length of a string.
 *  The function loads 32 bytes at a time and checks if there is a zero byte in the chunk.
 *  If there is a zero byte, it returns the position of the zero byte in the 32 bytes chunk.
 *  If there is no zero byte, it increments the pointer by 32 bytes and repeats the process.
 *  The function also handles the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
 *  The function uses prefetching to improve performance.
*/

#include <immintrin.h>
#include <stdlib.h>
#include <stdint.h>

inline size_t ft_strlen_avx(const char *s)
{
	if (__builtin_expect(s == NULL, 0))
		return 0;
    
	const char		*ptr = s;
    __m256i			zero = _mm256_setzero_si256();
	uintptr_t		missalignement = (uintptr_t)s & 31;
	/*
		* If the pointer is not aligned on a 32 bytes boundary, the function handles the initial bytes separately. 
		* It loads 32 bytes from the memory pointed by ptr and checks if there is a zero byte in the chunk.
		* If there is a zero byte, it returns the position of the zero byte in the 32 bytes chunk.
		* If there is no zero byte, it increments the pointer by 32 bytes and repeats the process.
	*/
	if (missalignement)
	{
		__m256i data = _mm256_loadu_si256((const __m256i *)s);
		__m256i cmp = _mm256_cmpeq_epi8(data, zero);
		uint32_t mask = _mm256_movemask_epi8(cmp);

		if (mask)
			return (s - ptr) + __builtin_ctz(mask);
		s += 32 - missalignement;
	}
	/*
		* Prefetch the next 64 bytes to improve performance.
		* The _MM_HINT_NTA hint is used to indicate that the data is not accessed again soon.
		* This hint is useful when the data is not accessed sequentially.
		* The _MM_HINT_T0 hint is used to indicate that the data is accessed soon.
		* This hint is useful when the data is accessed sequentially.
	*/
	_mm_prefetch(s + 64, _MM_HINT_NTA);
    while (1)
    {
        _mm_prefetch(s + 128, _MM_HINT_NTA);
        __m256i data = _mm256_loadu_si256((const __m256i *)s);
        __m256i cmp = _mm256_cmpeq_epi8(data, zero);
        uint32_t mask = _mm256_movemask_epi8(cmp);
		/*
			* If there is a zero byte in the chunk, the function returns 
			* the position of the zero byte in the 32 bytes chunk.
		* */
        if (mask)
            return (s - ptr) + __builtin_ctz(mask);
        s += 32;

    }
}
