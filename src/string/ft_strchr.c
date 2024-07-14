
/*
 * This implementation is based on the assumption that the string is not empty.
 * The function compares the string 32 bytes at a time using AVX2 instructions.
 * It first aligns the pointer to 32 bytes and compares the initial bytes
 * until the pointer is aligned.
 * Then it compares the string 32 bytes at a time using AVX2 instructions.
 * If the character is found, it returns a pointer to the character.
 * If the function reaches the end of the string, it returns NULL.
 * The function is optimized for large strings and strings with a length multiple of 32.
*/

#include <stdint.h>
#include <immintrin.h>
#include <stdlib.h>
#include <config.h>


char *ft_strchr(const char *p, int ch)
{
	if (__builtin_expect(p == NULL, 0))
		return (NULL);

	const unsigned char		*ptr = (const unsigned char *)p;
	const unsigned char		c = (unsigned char)ch;
	size_t					offset = (uintptr_t)ptr & 31;

	if (offset)
	{
		size_t align_size = VEC_SIZE - offset;
		for (size_t i = 0; i < align_size; i++)
		{
			if (ptr[i] == c)
				return (char *)(ptr + i);
			if (ptr[i] == '\0')
				return NULL;
		}
		ptr += align_size;
	}

	const __m256i		v = _mm256_set1_epi8(c);
	while (1)
	{
		__m256i data = _mm256_loadu_si256((const __m256i *)ptr);
		__m256i cmp = _mm256_cmpeq_epi8(data, v);
		int mask = _mm256_movemask_epi8(cmp);
		if (mask != 0)
			return (char *)(ptr + __builtin_ctz(mask));
		ptr += VEC_SIZE;
		_mm_prefetch(ptr, _MM_HINT_T0);
	}
}
