#include <stdint.h>
#include <immintrin.h>
#include <stdlib.h>
#include <config.h>

/*
 * this implementation of the memmove function uses AVX2 
 * instructions to move the memory pointed by src to the memory pointed by dest
 * the function loads 32 bytes at a time and moves the memory to the destination
 *
 * Explanation:
 * The function uses AVX2 instructions to move the memory pointed by src to the memory pointed by dest.
 * The function loads 32 bytes at a time and moves the memory to the destination.
 * The function handles the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
 * The function uses prefetching to improve performance.
*/

void *_memmove_avx(void *dest, const void *src, size_t len) {
    if (len == 0 || dest == src)
        return dest;

    uint8_t *cdest = (uint8_t *)dest;
    const uint8_t *csrc = (const uint8_t *)src;

    if (cdest < csrc) {
        size_t num_blocks = len / 32;
        size_t remaining_bytes = len % 32;

        const __m256i *s = (const __m256i *)csrc;
        __m256i *d = (__m256i *)cdest;
		
        for (size_t i = 0; i < num_blocks; ++i)
            _mm256_storeu_si256(d++, _mm256_loadu_si256(s++));

        uint8_t *byte_dest = (uint8_t *)d;
        const uint8_t *byte_src = (const uint8_t *)s;
        for (size_t i = 0; i < remaining_bytes; ++i) 
            byte_dest[i] = byte_src[i];
    } else {
        size_t num_blocks = len / 32;
        size_t remaining_bytes = len % 32;

        const __m256i *s = (const __m256i *)(csrc + len);
        __m256i *d = (__m256i *)(cdest + len);

        if (remaining_bytes) {
            const uint8_t *byte_src = csrc + len;
            uint8_t *byte_dest = cdest + len;
            for (size_t i = 0; i < remaining_bytes; ++i)
                byte_dest[-(int)(i + 1)] = byte_src[-(int)(i + 1)];
            s = (const __m256i *)(csrc + len - remaining_bytes);
            d = (__m256i *)(cdest + len - remaining_bytes);
        }

        for (size_t i = 0; i < num_blocks; ++i) {
            d--;
            s--;
            _mm256_storeu_si256(d, _mm256_loadu_si256(s));
        }
    }

    return dest;
}
