#include <stdint.h>
#include <immintrin.h>
#include <stdlib.h>
#include "../../libft.h"
/*
 *  this implementation of the memcpy function using AVX2 instructions
 *  less instruction, less cache misses, less branch mispredictions
*/

	/*
		* handle the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
		* load 32 bytes from the memory pointed by s and store them in the memory pointed by d.
		* prefetch the next 32 bytes to improve performance.
	*/

	/*
		* chunks is the number of 32 bytes chunks in the memory block.
		* remaining_bytes is the number of bytes that are not part of a 32 bytes chunk.
		* The function copies the memory 32 bytes at a time.
		* The function uses prefetching to improve performance.
	*/




inline void *ft_memcpy(void *dest, const void *src, size_t n) 
{
    void *ret = dest;
    size_t prefetch_distance = 64;
    size_t offset = 0;
    for (size_t i = 0; i < n; i += prefetch_distance) 
        _mm_prefetch((const char*)src + i + prefetch_distance, _MM_HINT_T0);

    while (n >= 32) {
        __m256i data = _mm256_loadu_si256((__m256i*)((char*)src + offset));
        _mm256_storeu_si256((__m256i*)((char*)dest + offset), data);

        offset += 32;
        n -= 32;
		_mm_prefetch((const char*)(src + offset + 32), _MM_HINT_T0);
    }

    if (n > 0) {
        __asm__ volatile (
            "rep movsb"
            : "+D" (dest), "+S" (src), "+c" (n)
            :
            : "memory"
        );
    }
    return ret;
}
