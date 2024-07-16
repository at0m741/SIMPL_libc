/*
	* This implementation is based on the assumption that the strings are not equal
* and that n is not 0.
* The function compares the strings 32 bytes at a time using AVX2 instructions.
* It first aligns the pointers to 32 bytes and compares the initial bytes
* until the pointers are aligned.
	* Then it compares the strings 32 bytes at a time using AVX2 instructions.
	* If a difference is found, it returns the difference.
	* If the strings are equal, it returns 0.
	* If the function reaches the end of the strings, it returns 0.
	* The function is optimized for large strings and strings with a length multiple of 32.
*/

#include <stdlib.h>
#include <stdint.h>
#include <immintrin.h>

inline int ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	if (__builtin_expect(n == 0, 0) || __builtin_expect(s1 == s2, 0))
		return 0;

    const char		*ptr1 = s1;
    const char		*ptr2 = s2;
    size_t			chunks = n / 32;
	uintptr_t		align1 = (uintptr_t)ptr1 & 31;
	uintptr_t		align2 = (uintptr_t)ptr2 & 31;


    if (align1 || align2)
    {
        while (n && ((uintptr_t)ptr1 & 31) && ((uintptr_t)ptr2 & 31))
        {
            if (*ptr1 != *ptr2)
                return (unsigned char)*ptr1 - (unsigned char)*ptr2;
            ptr1++;
            ptr2++;
            n--;
        }
        chunks = n / 32;
    }


    while (chunks--)
    {
        __m256i v1 = _mm256_loadu_si256((const __m256i *)ptr1);
        __m256i v2 = _mm256_loadu_si256((const __m256i *)ptr2);
        __m256i cmp = _mm256_cmpeq_epi8(v1, v2);
        int mask = _mm256_movemask_epi8(cmp);

        if (mask != -1)
        {
            for (int i = 0; i < 32; i++)
            {
                if (ptr1[i] != ptr2[i])
                    return (unsigned char)ptr1[i] - (unsigned char)ptr2[i];
            }
        }
        ptr1 += 32;
        ptr2 += 32;
        n -= 32;
		_mm_prefetch(ptr1, _MM_HINT_T0);
		_mm_prefetch(ptr2, _MM_HINT_T0);
    }

	n %= 32;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (unsigned char)*ptr1 - (unsigned char)*ptr2;
		ptr1++;
		ptr2++;
	}
	return 0;

}
