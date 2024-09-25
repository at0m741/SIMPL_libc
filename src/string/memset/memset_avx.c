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

#define BITS 0x0101010101010101ULL

/*
* 0x0101010101010101ULL is a 64-bit constant with the value 0x01 repeated 8 times.
* This constant is used to set 8 bytes to the value c.
*
* in binary 0x01 is 0000 0001 so :
*
* 00000001 00000001 00000001 00000001 
* 00000001 00000001 00000001 00000001
*
*/

void *_memset_avx(void *s, int c, size_t n) 
{
    unsigned char *p = (unsigned char *)s;

    if (n == 0) return s;

    __m256i fill = _mm256_set1_epi8((unsigned char)c);

    size_t misalign = ((uintptr_t)p) & 31;
    size_t align_size = misalign ? (32 - misalign) : 0;

    if (align_size > n) align_size = n;

    for (size_t i = 0; i < align_size; i++) {
        *p++ = c;
        n--;
    }

    while (n >= 32) {
        _mm256_storeu_si256((__m256i *)p, fill);
        p += 32;
        n -= 32;
    }
	
	while (n >= 16) {
		_mm_storeu_si128((__m128i *)p, _mm256_castsi256_si128(fill));
		p += 16;
		n -= 16;
	}

    while (n >= 8) {
        *(uint64_t *)p = (uint64_t)(unsigned char)c * BITS;
        p += 8;
        n -= 8;
    }

    while (n--) {
		*p++ = c;
    }
    return s;
}

