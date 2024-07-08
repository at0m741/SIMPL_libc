#include "../libft.h"

inline void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dst;
	unsigned char *s = (unsigned char *)src;

	/* check alignment */
	size_t dst_align = (uintptr_t)dst % 32;
	size_t initial_bytes = 0;
	/* if first byte is not aligned */
	/* copy initial bytes */
	if (dst_align != 0)
	{
		initial_bytes = 32 - dst_align;
		if (initial_bytes > n)
			initial_bytes = n;
		for (size_t i = 0; i < initial_bytes; i++)
			*d++ = *s++;
	}

	/* copy 32 bytes at a time */
	/* using AVX2 intrinsics after a prefetch in the cache using _mm_prefetch*/
	/* _MM_HINT_T0 is the default value to load in L1 cache*/
	size_t chunks = n / 32;
	size_t remaining_bytes = n % 32;

	_mm_prefetch(s, _MM_HINT_T0);
	_mm_prefetch(d, _MM_HINT_T0);

	for (size_t i = 0; i < chunks; i++)
	{
		__m256i chunk = _mm256_loadu_si256((__m256i *)s);
		_mm256_storeu_si256((__m256i *)d, chunk);
		s += 32;
		d += 32;
	}
	/* check if there are remaining bytes */
	/* copy remaining bytes as the normal way */
	return dst;
}

