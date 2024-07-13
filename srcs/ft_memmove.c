#include "../libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
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
    }else{
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

