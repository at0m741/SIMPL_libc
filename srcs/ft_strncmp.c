#include "../libft.h"

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
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    const char *ptr1 = s1;
    const char *ptr2 = s2;
    size_t chunks = n / 32;
	if (__builtin_expect(n == 0, 0) || __builtin_expect(s1 == s2, 0))
		return 0;

    uintptr_t align1 = (uintptr_t)ptr1 & 31;
	uintptr_t align2 = (uintptr_t)ptr2 & 31;
    if (align1 != 0 || align2 != 0)
    {
        size_t initial_bytes = 32 - (align1 > align2 ? align1 : align2);
        if (initial_bytes > n)
            initial_bytes = n;
        for (size_t i = 0; i < initial_bytes; i++)
        {
            if  (!__builtin_expect(ptr1[i] == ptr2[i], 1))

                return (unsigned char)ptr1[i] - (unsigned char)ptr2[i];
        }

        ptr1 += initial_bytes;
        ptr2 += initial_bytes;
        n -= initial_bytes;
        chunks = n / 32;
    }
    const __m256i *vec_ptr1 = (const __m256i *)ptr1;
    const __m256i *vec_ptr2 = (const __m256i *)ptr2;


    for (size_t i = 0; i < chunks; i++)
    {
        __m256i tmp1 = _mm256_loadu_si256(vec_ptr1 + i);
        __m256i tmp2 = _mm256_loadu_si256(vec_ptr2 + i);
        __m256i cmp1 = _mm256_cmpeq_epi8(tmp1, tmp2);
        int mask = _mm256_movemask_epi8(cmp1);
        if (_mm256_movemask_epi8(cmp1) != -1)
		{
		    size_t diff_index = i * 32 + __builtin_ctz(~mask);
			return (unsigned char)ptr1[diff_index] - (unsigned char)ptr2[diff_index];
		}
    }

    ptr1 += chunks * 32;
    ptr2 += chunks * 32;

    return 0;
}
