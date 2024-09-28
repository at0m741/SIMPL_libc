/*
	* this implementation of the memset function uses AVX2 
*	* instructions to set the memory pointed by b to the value c 
*	* the function loads 32 bytes at a time and sets the memory to the value c
*
*	* Explanation:
*	* The function uses AVX2 instructions to set the memory pointed by b to the value c.
*	* The function loads 32 bytes at a time and sets the memory to the value c.
*	* The function handles the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
*	* The function uses prefetching to improve performance.
*/

#include <stdint.h>
#include <immintrin.h>
#include <config.h>



#define REP_STOSB_THRESHOLD 2048
#define UNROLL_SIZE 64
#define VEC_SIZE 32

void *_memset_avx(void* dest, int c, size_t n) {
    unsigned char* d = (unsigned char*)dest;
    uint8_t value = (uint8_t)c;

    if (n < VEC_SIZE) {
        for (size_t i = 0; i < n; i++) {
            d[i] = value;
        }
        return dest;
    }

    if (n <= 2 * VEC_SIZE) {
        for (size_t i = 0; i < n; i++) {
            d[i] = value;
        }
        return dest;
    }

    if (n > REP_STOSB_THRESHOLD) {
        __asm__ volatile (
            "rep stosb"
            : "+D" (d), "+c" (n)
            : "a" (value)
            : "memory"
        );
    } else {
        __m256i vec = _mm256_set1_epi8(value);
        size_t vec_count = n / VEC_SIZE;
        size_t remainder = n & VEC_SIZE - 1;
		_mm_prefetch((const char*)d + UNROLL_SIZE, _MM_HINT_T0);
        for (size_t i = 0; i < vec_count; i++) {
            _mm256_storeu_si256((__m256i*)d, vec);
			_mm256_storeu_si256((__m256i*)(d + 32), vec);
			_mm256_storeu_si256((__m256i*)(d + 64), vec);
            d += UNROLL_SIZE;
        }

        for (size_t i = 0; i < remainder; i++) {
            d[i] = value;
        }
    }
	_mm256_zeroupper();
    return dest;
}

