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



void *_memcpy_avx(void *dest, const void *src, size_t n) 
{
	if (__builtin_expect(n == 0, 0) ||\
		__builtin_expect(dest == src, 0) ||\
		__builtin_expect(n > 0x7fffffffffffffff, 0) ||\
		__builtin_expect(dest == NULL || src == NULL, 0))
		return dest;

    void *ret = dest;
    uintptr_t dest_ptr = (uintptr_t)dest;
    uintptr_t src_ptr = (uintptr_t)src;

    while ((dest_ptr % 32 != 0) && n > 0) {
        *(char *)dest_ptr = *(const char *)src_ptr;
        dest_ptr++;
        src_ptr++;
        n--;
    }

    while (n >= 256) {
        _mm_prefetch((const char *)(src_ptr + 256), _MM_HINT_T0);
        for (int i = 0; i < 256; i += 32) {
            __m256i data = _mm256_loadu_si256((const __m256i *)(src_ptr + i));
            _mm256_storeu_si256((__m256i *)(dest_ptr + i), data);
        }
        src_ptr += 256;
        dest_ptr += 256;
        n -= 256;
    }

    while (n >= 32) {
        __m256i data = _mm256_loadu_si256((const __m256i *)src_ptr);
        _mm256_storeu_si256((__m256i *)dest_ptr, data);
        src_ptr += 32;
        dest_ptr += 32;
        n -= 32;
    }

    if (n >= 16) {
        __m128i data = _mm_loadu_si128((const __m128i *)src_ptr);
        _mm_storeu_si128((__m128i *)dest_ptr, data);
        src_ptr += 16;
        dest_ptr += 16;
        n -= 16;
    }

    while (n > 0) {
        *(char *)dest_ptr = *(const char *)src_ptr;
        dest_ptr++;
        src_ptr++;
        n--;
    }

    return ret;
}
