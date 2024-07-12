#include "../libft.h"

/*
 *  this implementation of the memcpy function using AVX2 instructions
 *  less instruction, less cache misses, less branch mispredictions
*/

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    size_t dst_align = (uintptr_t)dst & 31;
    size_t initial_bytes = 0;
	/*
		* handle the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
		* load 32 bytes from the memory pointed by s and store them in the memory pointed by d.
		* prefetch the next 32 bytes to improve performance.
	*/
    if (dst_align != 0)
    {
        initial_bytes = 32 - dst_align;
        if (initial_bytes > n)
            initial_bytes = n;
        for (size_t i = 0; i < initial_bytes; i++)
		{
            *d++ = *s++;
			_mm_prefetch((const char *)(s), _MM_HINT_T0);
		}
        n -= initial_bytes;
    }

	/*
		* chunks is the number of 32 bytes chunks in the memory block.
		* remaining_bytes is the number of bytes that are not part of a 32 bytes chunk.
		* The function copies the memory 32 bytes at a time.
		* The function uses prefetching to improve performance.
	*/
    size_t chunks = n / 256;
    size_t remaining_bytes = n % 256;
    for (size_t i = 0; i < chunks; i++)
    {

        __m256i chunk0 = _mm256_loadu_si256((__m256i *)(s + 0));
        _mm256_storeu_si256((__m256i *)(d + 0), chunk0);

        s += 256;
        d += 256;
        _mm_prefetch((const char *)(s + 256), _MM_HINT_T0);
        _mm_prefetch((const char *)(d + 256), _MM_HINT_T0);
    }
    for (size_t i = 0; i < initial_bytes; i++)
    {
        *d++ = *s++;
        _mm_prefetch((const char *)(s), _MM_HINT_T0);
    }

    return dst;
}
