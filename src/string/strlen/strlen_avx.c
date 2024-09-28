
/* check if the vector v contains a zero byte */
/* return 0 if no zero byte is found, otherwise return a non-zero value */

/*
** trying to benchmark Glibc.... but skill issue atm

* using _mm256_setzero_si256() to create a vector of 32 zero bytes bc assingning a 0 is to lower (yes I know it's a bit overkill)
* using _mm256_loadu_si256() to load 32 bytes from the memory pointed by ptr in asm :
*                      vpcmpeqb ymm1, ymm0, ymmword ptr [rsi + rcx + 32]

* using has_zero_byte() to check if the vector v contains a zero byte
__builtin_ctz() is a builtin function that returns the number of trailing 0-bits
*/

#include <stdlib.h>
#include <config.h>
#include <immintrin.h>


uint64_t strlen_avx(const char *str) 
{
    if (__builtin_expect(str == NULL, 0))
		return 0;

    const char *original_ptr = str;  
    __m256i ymm_zero = _mm256_set1_epi8(0);

    uintptr_t misalignment = (uintptr_t)str & 31;
    if (misalignment != 0) 
    {
        int64_t offset = 32 - misalignment;
        __m256i ymm_data = _mm256_loadu_si256((__m256i*)str);
        __m256i cmp_result = _mm256_cmpeq_epi8(ymm_zero, ymm_data);
        int32_t mask = _mm256_movemask_epi8(cmp_result);

		mask >>= misalignment;

        if (mask != 0) 
        {
            int32_t index = __builtin_ctz(mask);
			_mm256_zeroupper();
            return (uintptr_t)(str + index) - (uintptr_t)original_ptr;
        }

        str += offset;
    }
	uintptr_t page_offset = (uintptr_t)str & 31;
    while (1) 
    {
        __m256i ymm_data = _mm256_load_si256((__m256i*)str);  
        __m256i cmp_result = _mm256_cmpeq_epi8(ymm_zero, ymm_data);
        int32_t mask = _mm256_movemask_epi8(cmp_result);
		
		mask >>= page_offset;
        if (mask != 0) 
        {
            int32_t index = __builtin_ctz(mask);
			_mm256_zeroupper();
            return (uintptr_t)(str + index) - (uintptr_t)original_ptr;
        }

        str += 32;
    }
	_mm256_zeroupper();

    return 0;
}

/*  */
/* void test (){ */
/*  */
/* 	char *s; */
/* 	char *d; */
/* 	UNROLL_4(_mm256_storeu_si256(d++, _mm256_loadu_si256(s++))) */
/* 	 */
/* } */
