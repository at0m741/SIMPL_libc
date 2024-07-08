#include "../libft.h"

void *ft_memset(void *b, int c, size_t len) 
{
    unsigned char *ptr = (unsigned char *)b;
    unsigned char value = (unsigned char)c;

    size_t alignment_offset = (uintptr_t)ptr % 32;
    size_t initial_bytes = 0;

    if (alignment_offset != 0) 
    {
        initial_bytes = 32 - alignment_offset;
        if (initial_bytes > len)
            initial_bytes = len;

        for (size_t i = 0; i < initial_bytes; i++)
            ptr[i] = value;

        ptr += initial_bytes;
        len -= initial_bytes;
    }

    size_t chunks = len / 32;
    size_t remainings = len % 32;

    __m256i v = _mm256_set1_epi8(value);
	_mm_prefetch((const char *)(ptr), _MM_HINT_T0);
    // Prefetch data
    for (size_t i = 0; i < chunks; i += 8)
        _mm_prefetch((const char *)(ptr + i * 32), _MM_HINT_T1);

    for (size_t i = 0; i < chunks; i++)
        _mm256_storeu_si256((__m256i *)(ptr + i * 32), v);

    for (size_t i = 0; i < remainings; i++)
        ptr[chunks * 32 + i] = value;

    return b;
}

