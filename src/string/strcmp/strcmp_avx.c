#include <stdint.h>
#include <immintrin.h>

#define VEC_SIZE 32

int _strcmp_avx(const char *s1, const char *s2, size_t n) {
    size_t i = 0;
    __m256i ymm7 = _mm256_setzero_si256();

    while (i < n) {
        __m256i ymm1 = _mm256_loadu_si256((__m256i*)(s1 + i));
        __m256i ymm0 = _mm256_cmpeq_epi32(ymm1, _mm256_loadu_si256((__m256i*)(s2 + i)));
        ymm0 = _mm256_min_epu32(ymm1, ymm0);
        ymm0 = _mm256_cmpeq_epi32(ymm7, ymm0);
        unsigned int mask = _mm256_movemask_epi8(ymm0);

        if (mask != 0) {
            unsigned long index = _tzcnt_u32(mask);
            if (index >= n) return 0;


            uint8_t c1 = ((uint8_t*)s1)[i + index];
            uint8_t c2 = ((uint8_t*)s2)[i + index];
            if (c1 != c2) return c1 - c2;
        }

        i += VEC_SIZE;
    }

    _mm256_zeroupper();
    return 0;
}
