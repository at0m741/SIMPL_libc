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

#define PREFETCH_SIZE 64
#define LARGE_THRESHOLD 524288 
#define VEC_SIZE 32

void *_memmove_avx(void *dest, const void *src, size_t n) 
{
    if (dest == NULL || src == NULL || n == 0)
        return dest;

    char *destp = (char *)dest;
    const char *srcp = (const char *)src;

    size_t misalignment = ((uintptr_t)destp % VEC_SIZE);
    if (misalignment != 0) {
        size_t adjust = VEC_SIZE - misalignment;
        if (adjust > n) adjust = n;
        while (adjust--) {
            *destp++ = *srcp++;
            n--;
        }
    }

    size_t num_avx_iterations = n / VEC_SIZE;
    size_t remainder = n % VEC_SIZE;

    if (n >= LARGE_THRESHOLD) {
        for (size_t i = 0; i < n; i += PREFETCH_SIZE)
            _mm_prefetch(srcp + i, _MM_HINT_T0);

        while (num_avx_iterations >= 8) {
            __m256i d0 = _mm256_stream_load_si256((const __m256i *)srcp);
            __m256i d1 = _mm256_stream_load_si256((const __m256i *)(srcp + VEC_SIZE));
            __m256i d2 = _mm256_stream_load_si256((const __m256i *)(srcp + 2 * VEC_SIZE));
            __m256i d3 = _mm256_stream_load_si256((const __m256i *)(srcp + 3 * VEC_SIZE));
            __m256i d4 = _mm256_stream_load_si256((const __m256i *)(srcp + 4 * VEC_SIZE));
            __m256i d5 = _mm256_stream_load_si256((const __m256i *)(srcp + 5 * VEC_SIZE));
            __m256i d6 = _mm256_stream_load_si256((const __m256i *)(srcp + 6 * VEC_SIZE));
            __m256i d7 = _mm256_stream_load_si256((const __m256i *)(srcp + 7 * VEC_SIZE));
            
            _mm256_stream_si256((__m256i *)destp, d0);
            _mm256_stream_si256((__m256i *)(destp + VEC_SIZE), d1);
            _mm256_stream_si256((__m256i *)(destp + 2 * VEC_SIZE), d2);
            _mm256_stream_si256((__m256i *)(destp + 3 * VEC_SIZE), d3);
            _mm256_stream_si256((__m256i *)(destp + 4 * VEC_SIZE), d4);
            _mm256_stream_si256((__m256i *)(destp + 5 * VEC_SIZE), d5);
            _mm256_stream_si256((__m256i *)(destp + 6 * VEC_SIZE), d6);
            _mm256_stream_si256((__m256i *)(destp + 7 * VEC_SIZE), d7);

            srcp += 8 * VEC_SIZE;
            destp += 8 * VEC_SIZE;
            num_avx_iterations -= 8;
            _mm_prefetch(srcp + (8 * VEC_SIZE), _MM_HINT_T0);
        }

        _mm_sfence();
    } else {
        while (num_avx_iterations--) {
            __m256i data = _mm256_loadu_si256((const __m256i *)srcp);
            _mm256_storeu_si256((__m256i *)destp, data);
            srcp += VEC_SIZE;
            destp += VEC_SIZE;
        }
    }

    if (remainder > 0) {
        if (remainder >= 16) {
			_mm_prefetch(srcp + 16, _MM_HINT_T0);
            __m128i data = _mm_loadu_si128((const __m128i *)srcp);
            _mm_storeu_si128((__m128i *)destp, data);
            srcp += 16;
            destp += 16;
            remainder -= 16;
        }
        while (remainder--)
            *destp++ = *srcp++;
    }
	_mm256_zeroupper();
    return dest;
}
