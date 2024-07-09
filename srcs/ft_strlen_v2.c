/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:20:48 by ltouzali          #+#    #+#             */
/*   Updated: 2024/07/09 21:34:51 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

/*
 *  this is the second implementation of the strlen function using AVX2 instructions
 *  less instruction, less cache misses, less branch mispredictions
 *  this implementation is faster than the first one but handle less cases 
*/

/*
 *  Explanation:
 *  The function uses AVX2 instructions to find the length of a string.
 *  The function loads 32 bytes at a time and checks if there is a zero byte in the chunk.
 *  If there is a zero byte, it returns the position of the zero byte in the 32 bytes chunk.
 *  If there is no zero byte, it increments the pointer by 32 bytes and repeats the process.
 *  The function also handles the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
 *  The function uses prefetching to improve performance.
*/

#define AVX2_ALIGNMENT 32
#define VEC_SIZE 32
#define CHAR_PER_VEC (VEC_SIZE / sizeof(char))
#define PAGE_SIZE 4096

size_t strlen_avx2(const char* str) 
{
	/* check if the pointer is null */
	/* if it is, return 0 */
	if (__builtin_expect(str == NULL, 0))
		return 0;

    const char*		ptr = str;
    __m256i			zero_mask = _mm256_setzero_si256();

    /* 
	 * check if the pointer is aligned on a 32 bytes boundary 
     *  if not, we need to handle the initial bytes separately 
     *  then we need to realign the pointer to 32 bytes boundary
	*/
	_mm_prefetch(ptr, _MM_HINT_NTA);
	_mm_prefetch(ptr + PAGE_SIZE, _MM_HINT_NTA);
	_mm_prefetch(ptr + 2 * PAGE_SIZE, _MM_HINT_NTA);
	_mm_prefetch(ptr + 3 * PAGE_SIZE, _MM_HINT_NTA);
	while (((uintptr_t)ptr & (VEC_SIZE - 1)) != 0) 
	{
		if (*ptr == '\0')
			return ptr - str;
		ptr++;
	}

	size_t offset = (uintptr_t)ptr & (VEC_SIZE - 1);
    if (offset) 
	{
	/*
	 * realignment
	 * then use simd to check for zero bytes
	 * the mask will be used to find the position of the zero byte 
	 * within the 32 bytes chunk, that means we need to find the 
	 * position of the first bit set to 1 in the mask 
	 * the cmp instruction will compare the data with the zero mask 
	*/
        size_t align_size = VEC_SIZE - offset;
        __m256i data = _mm256_loadu_si256((__m256i*)ptr);
        __m256i cmp = _mm256_cmpeq_epi8(data, zero_mask);
        int mask = _mm256_movemask_epi8(cmp);
        _mm_prefetch(ptr + align_size, _MM_HINT_NTA);
		_mm_prefetch(ptr + align_size + PAGE_SIZE, _MM_HINT_NTA);
		
		/* if the mask is not zero, then there is a zero byte in the chunk */
		if (mask)
            return ptr - str + __builtin_ctz(mask);
        
		ptr += align_size;
    }
	/*
		*this is the main loop, we will load 32 bytes at a time and check if there is a zero byte
		*if there is a zero byte, we will return the position of the zero byte in the 32 bytes chunk
		*if there is no zero byte, we will increment the pointer by 32 bytes and repeat the process
	*/

    while (1) 
	{
		/* load 32 bytes into the register to check for zero bytes */
        __m256i data1 = _mm256_load_si256((__m256i*)ptr);
		__m256i data2 = _mm256_load_si256((__m256i*)(ptr + VEC_SIZE));
		__m256i data3 = _mm256_load_si256((__m256i*)(ptr + 2 * VEC_SIZE));
		__m256i data4 = _mm256_load_si256((__m256i*)(ptr + 3 * VEC_SIZE));
       
		/* compare the data with the zero mask */
		__m256i cmp1 = _mm256_cmpeq_epi8(data1, zero_mask);
		__m256i cmp2 = _mm256_cmpeq_epi8(data2, zero_mask);
		__m256i cmp3 = _mm256_cmpeq_epi8(data3, zero_mask);
		__m256i cmp4 = _mm256_cmpeq_epi8(data4, zero_mask);

		/* find the position of the zero byte in the 32 bytes chunk */
		/* if there is a zero byte, return the position */
        int mask1 = _mm256_movemask_epi8(cmp1);
		int mask2 = _mm256_movemask_epi8(cmp2);
		int mask3 = _mm256_movemask_epi8(cmp3);
		int mask4 = _mm256_movemask_epi8(cmp4);
        if (mask1) {
            return ptr - str + __builtin_ctz(mask1);
        }
		if (mask2) {
			return ptr - str + VEC_SIZE + __builtin_ctz(mask1);
		}
		if (mask3) {
			return ptr - str + 2 * VEC_SIZE + __builtin_ctz(mask1);
		}
		if (mask4) {
			return ptr - str + 3 * VEC_SIZE + __builtin_ctz(mask1);
		}

        ptr += VEC_SIZE;
		/* prefetch the next 32 bytes */
		/* to reduce cache misses */
		_mm_prefetch(ptr, _MM_HINT_NTA);
		_mm_prefetch(ptr + PAGE_SIZE, _MM_HINT_NTA);
		_mm_prefetch(ptr + 2 * PAGE_SIZE, _MM_HINT_NTA);
		_mm_prefetch(ptr + 3 * PAGE_SIZE, _MM_HINT_NTA);
	}
}

