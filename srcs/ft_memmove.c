#include "../libft.h"

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
				_mm_prefetch((const char*)srcp + 64, _MM_HINT_T0);
				_mm_prefetch((const char*)destp + 64, _MM_HINT_T0);
            }
        }
        while (n--)
            *destp++ = *srcp++;
    }
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


void *ft_memmove_ERMS(void *dest, const void *src, size_t n) 
{
    void *ret = dest;

	if (__builtin_expect(dest == NULL || src == NULL, 0))
		return (NULL);

	if (n == 32)
	{
		_mm_prefetch((const char*)src + 32, _MM_HINT_T0);
		__m256i data = _mm256_loadu_si256((__m256i*)src);
		_mm256_storeu_si256((__m256i*)dest, data);
		return dest;
	}
	else if (n == 64)
	{
		_mm_prefetch((const char*)src + 64, _MM_HINT_T0);
		__m256i data0 = _mm256_loadu_si256((__m256i*)src);
		__m256i data1 = _mm256_loadu_si256((__m256i*)((char*)src + 32));
		_mm256_storeu_si256((__m256i*)dest, data0);
		_mm256_storeu_si256((__m256i*)((char*)dest + 32), data1);
		return dest;
	}
    if (dest < src) 
	{
        register size_t prefetch_distance = 64;

        for (size_t i = 0; i < n; i += prefetch_distance)
			_mm_prefetch((const char*)src + i, _MM_HINT_T0);

        __asm__ volatile (
            "rep movsb"
            : "+D" (dest), "+S" (src), "+c" (n)
            :
            : "memory"
        );
    }
	else if (dest > src)
	{
        dest = (char*)dest + n - 1;
        src = (const char*)src + n - 1;
		register size_t prefetch_distance = 64;

		for (size_t i = 0; i < n; i += prefetch_distance)
			_mm_prefetch((const char*)src - i, _MM_HINT_T0);

        __asm__ volatile (
            "std\n"
            "rep movsb\n"
            "cld"
            : "+D" (dest), "+S" (src), "+c" (n)
            :
            : "memory"
        );
    }

	return ret;
}


