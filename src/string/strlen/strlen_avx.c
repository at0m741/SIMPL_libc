
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


size_t _strlen_avx(const char *str) {
    if (__builtin_expect(str == NULL, 0))
        return 0;

    const char *original_ptr = str;
    __m256i ymm_zero = _mm256_setzero_si256();

    uintptr_t misalignment = (uintptr_t)str & 31;
    if (misalignment != 0) {
        uintptr_t offset = 32 - misalignment;
        __m256i ymm_data = _mm256_loadu_si256((const __m256i *)str);
        int32_t mask = _mm256_movemask_epi8(_mm256_cmpeq_epi8(ymm_data, ymm_zero));

        if (mask != 0) {
            int32_t index = __builtin_ctz(mask);
            return (str + index) - original_ptr;
        }
        str += offset;
    }

    while (1) {
        _mm_prefetch((const char *)(str + 256), _MM_HINT_T0);

        __m256i ymm_data1 = _mm256_load_si256((const __m256i *)(str));
        __m256i ymm_data2 = _mm256_load_si256((const __m256i *)(str + 32));
        __m256i ymm_data3 = _mm256_load_si256((const __m256i *)(str + 64));
        __m256i ymm_data4 = _mm256_load_si256((const __m256i *)(str + 96));

        __m256i cmp_result1 = _mm256_cmpeq_epi8(ymm_data1, ymm_zero);
        __m256i cmp_result2 = _mm256_cmpeq_epi8(ymm_data2, ymm_zero);
        __m256i cmp_result3 = _mm256_cmpeq_epi8(ymm_data3, ymm_zero);
        __m256i cmp_result4 = _mm256_cmpeq_epi8(ymm_data4, ymm_zero);

        int32_t mask1 = _mm256_movemask_epi8(cmp_result1);
        int32_t mask2 = _mm256_movemask_epi8(cmp_result2);
        int32_t mask3 = _mm256_movemask_epi8(cmp_result3);
        int32_t mask4 = _mm256_movemask_epi8(cmp_result4);

        if (mask1 != 0) {
            int32_t index = __builtin_ctz(mask1);
            return (str + index) - original_ptr;
        }
        if (mask2 != 0) {
            int32_t index = __builtin_ctz(mask2);
            return (str + 32 + index) - original_ptr;
        }
        if (mask3 != 0) {
            int32_t index = __builtin_ctz(mask3);
            return (str + 64 + index) - original_ptr;
        }
        if (mask4 != 0) {
            int32_t index = __builtin_ctz(mask4);
            return (str + 96 + index) - original_ptr;
        }

        str += 128; 
    }
}

/*  */
/* void test (){ */
/*  */
/* 	char *s; */
/* 	char *d; */
/* 	UNROLL_4(_mm256_storeu_si256(d++, _mm256_loadu_si256(s++))) */
/* 	 */
/* } */
