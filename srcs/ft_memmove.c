#include "../libft.h"

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

void *ft_memmove(void *dest, const void *src, size_t n)
{
	if (__builtin_expect(dest == NULL || src == NULL, 0))
		return (NULL);
    const char *srcp = (const char *)src;
    char *destp = (char *)dest;
    
    if (destp < srcp || destp >= srcp + n)
    {
        uintptr_t srcp_aligned = (uintptr_t)srcp & 0x1F;
        uintptr_t destp_aligned = (uintptr_t)destp & 0x1F;
		
        if (srcp_aligned == 0 && destp_aligned == 0)
        {
            while (n >= 32)
            {
                __m256i src_data = _mm256_load_si256((__m256i*)srcp);
                _mm256_store_si256((__m256i*)destp, src_data);
                srcp += 32;
                destp += 32;
                n -= 32;
				/* prefetch the next 64 bytes to improve performance */
				/* the _MM_HINT_T0 hint is used to indicate that the data is accessed again soon */
				_mm_prefetch((const char*)srcp + 64, _MM_HINT_T0);
				_mm_prefetch((const char*)destp + 64, _MM_HINT_T0);
            }
        }
        while (n--)
            *destp++ = *srcp++;
    }
	/* handle the case where the destination overlaps the source */
	/* copy the memory from the end to the beginning */
	/* this is done to avoid overwriting the source */
	/* the function uses prefetching to improve performance over cache misses */
	else
	{
        srcp += n;
        destp += n;
        
        uintptr_t srcp_aligned = (uintptr_t)srcp & 0x1F;
        uintptr_t destp_aligned = (uintptr_t)destp & 0x1F;
		_mm_prefetch((const char*)srcp - 64, _MM_HINT_T0);
		_mm_prefetch((const char*)destp - 64, _MM_HINT_T0);
        if (srcp_aligned == 0 && destp_aligned == 0)
        {
            while (n >= 32)
            {
                srcp -= 32;
                destp -= 32;
                __m256i src_data = _mm256_load_si256((__m256i*)srcp);
                _mm256_store_si256((__m256i*)destp, src_data);
                n -= 32;
            }
        }
        while (n--)
            *(--destp) = *(--srcp);
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

