#include "../libft.h"

inline void *ft_memset(void *b, int c, size_t len)
{
    if (len == 0)
        return b;

    __attribute__((aligned(32))) unsigned char *ptr = (unsigned char *)b;
    __attribute__((aligned(32))) unsigned char value = (unsigned char)c;

    size_t alignment_offset = (uintptr_t)ptr % 32;
    size_t initial_bytes = 0;

    if (alignment_offset != 0) {
        initial_bytes = 32 - alignment_offset;
        // if the length is less than 32 bytes, we can't use AVX2
        if (initial_bytes > len) {
            initial_bytes = len;
        }
        /* memset the initial bytes */
        for (size_t i = 0; i < initial_bytes; i++) {
            ptr[i] = value;
        }
        ptr += initial_bytes;
        len -= initial_bytes;
    }
    
    /* memset the rest of the buffer */
    size_t chunks = len / 32;
    size_t remainings = len % 32;

    __m256i v = _mm256_set1_epi8(value);
    _mm_prefetch((const char *)(ptr + chunks * 32), _MM_HINT_T0);
    for (size_t i = 0; i < chunks; i++) {
        _mm256_storeu_si256((__m256i *)(ptr + i * 32), v);
    }

    for (size_t i = 0; i < remainings; i++) {
        ptr[chunks * 32 + i] = value;
    }

    return b - initial_bytes;
}