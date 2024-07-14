#include <stdint.h>
#include <immintrin.h>
#include <stdlib.h>

/*
 *  this implementation of the memcpy function using AVX2 instructions
 *  less instruction, less cache misses, less branch mispredictions
*/

inline void *ft_memcpy(void *dst, const void *src, size_t n)
{
	if (__builtin_expect(dst == NULL || src == NULL, 0))
		return (NULL);
    
	unsigned char			*d = (unsigned char *)dst;
    const unsigned char		*s = (const unsigned char *)src;
    size_t					dst_align = (uintptr_t)dst & 31;
    size_t					initial_bytes = 0;
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
    size_t		chunks = n / 32;
    for (size_t i = 0; i < chunks; i++)
    {
        __m256i chunk0 = _mm256_loadu_si256((__m256i *)(s + 0));
		__m256i chunk1 = _mm256_loadu_si256((__m256i *)(s + 32));
		__m256i chunk2 = _mm256_loadu_si256((__m256i *)(s + 64));
		__m256i chunk3 = _mm256_loadu_si256((__m256i *)(s + 96));
		__m256i chunk4 = _mm256_loadu_si256((__m256i *)(s + 128));
		__m256i chunk5 = _mm256_loadu_si256((__m256i *)(s + 160));
		__m256i chunk6 = _mm256_loadu_si256((__m256i *)(s + 192));
		__m256i chunk7 = _mm256_loadu_si256((__m256i *)(s + 224));
		__m256i chunk8 = _mm256_loadu_si256((__m256i *)(s + 256));
        _mm256_storeu_si256((__m256i *)(d + 0), chunk0);
		_mm256_storeu_si256((__m256i *)(d + 32), chunk1);
		_mm256_storeu_si256((__m256i *)(d + 64), chunk2);
		_mm256_storeu_si256((__m256i *)(d + 96), chunk3);
		_mm256_storeu_si256((__m256i *)(d + 128), chunk4);
		_mm256_storeu_si256((__m256i *)(d + 160), chunk5);
		_mm256_storeu_si256((__m256i *)(d + 192), chunk6);
		_mm256_storeu_si256((__m256i *)(d + 224), chunk7);
		_mm256_storeu_si256((__m256i *)(d + 256), chunk8);

        s += 32;
        d += 32;
        _mm_prefetch((const char *)(s + 224), _MM_HINT_T0);
        _mm_prefetch((const char *)(d + 224), _MM_HINT_T0);
    }

    for (size_t i = 0; i < initial_bytes; i++)
    {
        *d++ = *s++;
        _mm_prefetch((const char *)(s), _MM_HINT_T0);
    }

    return dst;
}


void *ft_memcpy_ERMS(void *dest, const void *src, size_t n) 
{
    void		*ret = dest;
    size_t		prefetch_distance = 64;

    for (size_t i = 0; i < n; i += prefetch_distance) 
		_mm_prefetch((const char*)src + i + prefetch_distance, _MM_HINT_T0);

    __asm__ volatile (
        "rep movsb"
        : "+D" (dest), "+S" (src), "+c" (n)
        : 
        : "memory"
    );

    return ret;
}
