#include <stdint.h>
#include <immintrin.h>

int _strcmp_sse(const char *s1, const char *s2) {
	__m128i v1, v2;
	while (1) {
		v1 = _mm_loadu_si128((__m128i *)s1);
		v2 = _mm_loadu_si128((__m128i *)s2);
		if (_mm_movemask_epi8(_mm_cmpeq_epi8(v1, v2)) != 0xFFFF) {
			break;
		}
		s1 += 16;
		s2 += 16;
	}
	while (*s1 && *s1 == *s2) {
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}
