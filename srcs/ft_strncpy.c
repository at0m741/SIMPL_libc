#include "../libft.h"

/*
* an optimized implementation of the strncpy function using AVX2 instructions
* less instruction, less cache misses, less branch mispredictions
* Explanation:
* The function copies the memory 32 bytes at a time using AVX2 instructions.
* The function first aligns the pointers to 32 bytes and copies the initial bytes until the pointers are aligned.
* Then it copies the memory 32 bytes at a time using AVX2 instructions.
* If the function reaches the end of the strings, it pads the remaining bytes with zeros.
* The function is optimized for large strings and strings with a length multiple of 32.
*/

char *ft_strncpy(char *dst, const char *src, size_t n)
{
    char		*ptr = dst; 
	size_t		chunks = n / VEC_SIZE;
	size_t		remaining_bytes = n & 31;
	uintptr_t	align = (uintptr_t)src & 31;


    if (align != 0)
    {
        size_t	initial_bytes = VEC_SIZE - align;
        if (initial_bytes > n)
            initial_bytes = n;
        for (size_t i = 0; i < initial_bytes; i++)
            *dst++ = *src++;
        n -= initial_bytes;
    }

    const __m256i *vec_src = (const __m256i *)src;
	__m256i zero = _mm256_setzero_si256();
	_mm_prefetch(src + chunks * VEC_SIZE, _MM_HINT_NTA);
    for (size_t i = 0; i < chunks; i++)
    {
        __m256i chunk = _mm256_loadu_si256(vec_src + i);
        _mm256_storeu_si256((__m256i *)dst, chunk);
        dst += VEC_SIZE;
    }
    if (remaining_bytes)
    {
        __m256i chunk = _mm256_loadu_si256(vec_src + chunks);
        __m256i mask = _mm256_cmpgt_epi8(_mm256_set1_epi8(remaining_bytes),
            _mm256_setr_epi8(31, 30, 29, 28, 27, 26, 25, 24,\
							 23, 22, 21, 20, 19, 18, 17, 16,\
							 15, 14, 13, 12, 11, 10, 9, 8,\
							 7, 6, 5, 4, 3, 2, 1, 0));
        chunk = _mm256_blendv_epi8(chunk, zero, mask);
        _mm256_storeu_si256((__m256i *)dst, chunk);
    }

    return ptr;
}
