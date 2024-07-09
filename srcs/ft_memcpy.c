#include "../libft.h"

inline void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    size_t dst_align = (uintptr_t)dst % 32;
    size_t initial_bytes = 0;

    // Align the destination to 32 bytes
    if (dst_align != 0)
    {
        initial_bytes = 32 - dst_align;
        if (initial_bytes > n)
            initial_bytes = n;
        for (size_t i = 0; i < initial_bytes; i++)
            *d++ = *s++;
        n -= initial_bytes;
    }

    // Prefetch source and destination
    _mm_prefetch((const char *)(s), _MM_HINT_T0);
    _mm_prefetch((const char *)(s + 64), _MM_HINT_T0);
    _mm_prefetch((const char *)(d), _MM_HINT_T0);
    _mm_prefetch((const char *)(d + 64), _MM_HINT_T0);

    size_t chunks = n / 256; // 256-bit registers, hence 256 bytes per iteration
    size_t remaining_bytes = n % 256;

    // Unrolled loop to handle 256 bytes per iteration
    for (size_t i = 0; i < chunks; i++)
    {
        _mm_prefetch((const char *)(s + 256), _MM_HINT_T0);
        _mm_prefetch((const char *)(d + 256), _MM_HINT_T0);

        __m256i chunk0 = _mm256_loadu_si256((__m256i *)(s + 0));
        __m256i chunk1 = _mm256_loadu_si256((__m256i *)(s + 32));
        __m256i chunk2 = _mm256_loadu_si256((__m256i *)(s + 64));
        __m256i chunk3 = _mm256_loadu_si256((__m256i *)(s + 96));
        __m256i chunk4 = _mm256_loadu_si256((__m256i *)(s + 128));
        __m256i chunk5 = _mm256_loadu_si256((__m256i *)(s + 160));
        __m256i chunk6 = _mm256_loadu_si256((__m256i *)(s + 192));
        __m256i chunk7 = _mm256_loadu_si256((__m256i *)(s + 224));

        _mm256_storeu_si256((__m256i *)(d + 0), chunk0);
        _mm256_storeu_si256((__m256i *)(d + 32), chunk1);
        _mm256_storeu_si256((__m256i *)(d + 64), chunk2);
        _mm256_storeu_si256((__m256i *)(d + 96), chunk3);
        _mm256_storeu_si256((__m256i *)(d + 128), chunk4);
        _mm256_storeu_si256((__m256i *)(d + 160), chunk5);
        _mm256_storeu_si256((__m256i *)(d + 192), chunk6);
        _mm256_storeu_si256((__m256i *)(d + 224), chunk7);

        s += 256;
        d += 256;
    }

    // Copy the remaining bytes
    for (size_t i = 0; i < remaining_bytes; i++)
        *d++ = *s++;

    return dst;
}

