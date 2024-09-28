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

void *ft_memmove_AVX2(void *dest, const void *src, size_t n) 
{
    if (dest == NULL || src == NULL)
        return NULL;

    char *destp = (char *)dest;
    const char *srcp = (const char *)src;

    if (n == 0)
        return dest;

    if (destp < srcp)
    {
        size_t prefetch_distance = 64;

        for (size_t i = 0; i < n; i += prefetch_distance)
            _mm_prefetch(srcp + i, _MM_HINT_T0);

        size_t num_avx_iterations = n / 32;
        size_t remainder = n % 32;

        while (num_avx_iterations--)
        {
            __m256i data = _mm256_loadu_si256((const __m256i *)srcp);
            _mm256_storeu_si256((__m256i *)destp, data);
            srcp += 32;
            destp += 32;
        }

        if (remainder > 0)
        {
            while (remainder--)
                *destp++ = *srcp++;
        }
    }
    else
    {
        destp += n;
        srcp += n;
        size_t prefetch_distance = 64;

        for (size_t i = 0; i < n; i += prefetch_distance)
            _mm_prefetch(srcp - i - prefetch_distance, _MM_HINT_T0);

        size_t num_avx_iterations = n / 32;
        size_t remainder = n % 32;

        while (num_avx_iterations--)
        {
            srcp -= 32;
            destp -= 32;
            __m256i data = _mm256_loadu_si256((const __m256i *)srcp);
            _mm256_storeu_si256((__m256i *)destp, data);
        }

        if (remainder > 0)
        {
            while (remainder--)
            {
                *(--destp) = *(--srcp);
            }
        }
    }

    return dest;
}
/*
* this implementation of the memmove function uses ERMS instructions to move the memory pointed by src to the memory pointed by dest
* the function loads 32 bytes at a time and moves the memory to the destination
* the function uses prefetching to improve performance
* the function handles the initial bytes separately if the pointer is not aligned on a 32 bytes boundary
*/


void *ft_memmove_ERMS_AVX2(void *dest, const void *src, size_t n) 
{
    void *ret = dest;
    register size_t prefetch_distance = 64;

    if (__builtin_expect(dest == NULL || src == NULL, 0))
        return NULL;
	/*
	* if n is 0, the function will return dest
	* if the src is not aligned on a 32 bytes boundary,
	* the function will handle the initial bytes separately
		* if n is less than 32 bytes, the function will copy the memory using the rep movsb instruction
	* if n is less than 64 bytes, the function will copy the memory using the rep movsb instruction
	*/
    if (n == 32) 
    {
        __m256i data = _mm256_loadu_si256((__m256i*)src);
        _mm256_storeu_si256((__m256i*)dest, data);
        return dest;
    } 
    else if (n == 64) 
    {
        __m256i data0 = _mm256_loadu_si256((__m256i*)src);
        __m256i data1 = _mm256_loadu_si256((__m256i*)((char*)src + 32));
        _mm256_storeu_si256((__m256i*)dest, data0);
        _mm256_storeu_si256((__m256i*)((char*)dest + 32), data1);
        return dest;
    }
	/*
	* if the destination is less than the source, the function will copy the memory from the beginning to the end
	* if the destination is greater than the source, the function will copy the memory from the end to the beginning	
	* the function uses prefetching to improve performance
	*/

    if (dest < src) 
    {
        for (size_t i = 0; i < n; i += prefetch_distance)
            _mm_prefetch((const char*)src + i, _MM_HINT_T0);

        size_t num_avx_iterations = n / 32;
        size_t remainder = n % 32;

        while (num_avx_iterations--) 
        {
            __m256i data = _mm256_loadu_si256((__m256i*)src);
            _mm256_storeu_si256((__m256i*)dest, data);
            src = (const char*)src + 32;
            dest = (char*)dest + 32;
        }

        if (remainder > 0) 
        {
            __asm__ volatile (
                "rep movsb"
                : "+D" (dest), "+S" (src), "+c" (remainder)
                :
                : "memory"
            );
        }
    } 
    else if (dest > src) 
    {
        dest = (char*)dest + n - 1;
        src = (const char*)src + n - 1;

        for (size_t i = 0; i < n; i += prefetch_distance)
            _mm_prefetch((const char*)src - i, _MM_HINT_T0);

        size_t num_avx_iterations = n / 32;
        size_t remainder = n % 32;

        while (num_avx_iterations--) 
        {
            dest = (char*)dest - 31;
            src = (const char*)src - 31;
            __m256i data = _mm256_loadu_si256((__m256i*)src);
            _mm256_storeu_si256((__m256i*)dest, data);
            src = (const char*)src - 1;
            dest = (char*)dest - 1;
        }

        if (remainder > 0) 
        {
            __asm__ volatile (
                "std\n"
                "rep movsb\n"
                "cld"
                : "+D" (dest), "+S" (src), "+c" (remainder)
                :
                : "memory"
            );
        }
    }

    return ret;
}


void *ft_memmove_ERMS(void *dest, const void *src, size_t n)
{
	if (dest == NULL || src == NULL)
		return NULL;
	__asm__ volatile (
		"rep movsb"
		: "+D" (dest), "+S" (src), "+c" (n)
		:
		: "memory"
	);
	return dest;
}
