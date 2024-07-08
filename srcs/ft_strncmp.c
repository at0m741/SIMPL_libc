#include "../libft.h"

inline int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    /* I'm gonna compare 32 bytes at a time */
    /* so I'm gonna divide n by 32 */
    /* and the remaining bytes will be compared after */
    /* yes I do have a degree in math, why do you ask? */
    size_t chunks = n & ~31;
    size_t remainings = n % 32;
    const __m256i *ptr1 = (const __m256i *)s1;
    const __m256i *ptr2 = (const __m256i *)s2;
    /*check if the pointer is aligned on a 32 bytes boundary*/
    /*if not, we need to handle the initial bytes separately*/
    /*then we need to realign the pointer to 32 bytes boundary*/

    uint8_t alignement_offset = (uintptr_t)s1 % AVX2_ALIGNMENT;
    if (alignement_offset != 0){
        size_t initial_bytes = AVX2_ALIGNMENT - alignement_offset;
        if (initial_bytes > n){
            initial_bytes = n;
        }
        for (size_t i = 0; i < initial_bytes; i++){
            if (s1[i] != s2[i])
                return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        ptr1 += initial_bytes;
        ptr2 += initial_bytes;
        n -= initial_bytes;
    }
    for (size_t i = 0; i < chunks; i++)
    {
        __m256i tmp1 = _mm256_loadu_si256(ptr1 + i);
        __m256i tmp2 = _mm256_loadu_si256(ptr2 + i);
        __m256i cmp  = _mm256_cmpeq_epi8(tmp1, tmp2);
        /*prefetching the next 32 bytes in L1 cache*/

        /* yes cmp is compare, if u didn't know buddy...... */
        uint32_t mask = _mm256_movemask_epi8(cmp);
        /* mask is in IT world what it is in real life, so have a noice day */
        if (mask != 0xFFFFFFFF)  /* it's just -1 but I live in a world where -1 is not a thing*/
        {
            size_t diff_index = i * 32 + __builtin_ctz(~mask);
            return (unsigned char)s1[diff_index] - (unsigned char)s2[diff_index];
        }
    }
    /*just in case you're wondering why I'm using char* instead of __m256i
    **its just in case the string is not aligned on a 32 bytes boundary
    **so I'm just gonna cast the __m256i to char* and compare the remainings bytes
    */
    /*cast, cast and cast again*/
    const char *char_ptr1 = (const char *)(ptr1 + chunks);
    const char *char_ptr2 = (const char *)(ptr2 + chunks);

    for (size_t i = 0; i < remainings; i++)
    {
        if (char_ptr1[i] != char_ptr2[i])
            return (int)((unsigned char)char_ptr1[i] - (unsigned char)char_ptr2[i]);
    }
    return 0;
}
