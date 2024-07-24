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


void *_memset_avx(void *s, int c, size_t n) 
{
    if (n == 0) return s;

    __attribute__((aligned(sizeof(__m256i)))) unsigned char *p = (unsigned char *)s;
    __m256i fill = _mm256_set1_epi8((unsigned char)c);

    size_t offset = ((uintptr_t)p) & 31;
    while (offset && n) {
        *p++ = c;
        --n;
        offset = ((uintptr_t)p) & 31;
	}

    while (n >= 32) {
        _mm256_storeu_si256((__m256i *)p, fill);
        p += 32;
        n -= 32;
    }

    while (n) {
        *p++ = c;
        --n;
    }

    return s;
}
