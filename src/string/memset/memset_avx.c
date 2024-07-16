/*
	* this implementation of the memset function uses AVX2 
*	* instructions to set the memory pointed by b to the value c 
*	* the function loads 32 bytes at a time and sets the memory to the value c
*
*	* Explanation:
*	* The function uses AVX2 instructions to set the memory pointed by b to the value c.
*	* The function loads 32 bytes at a time and sets the memory to the value c.
*	* The function handles the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
*	* The function uses prefetching to improve performance.
*/

#include <stdint.h>
#include <immintrin.h>
#include <stdlib.h>
#include <config.h>

void *_memset_avx(void *b, int c, size_t len) 
{
	if (__builtin_expect(b == NULL, 0) || len == 0)
		return b;
  
	unsigned char	*ptr = (unsigned char *)b;
    unsigned char	value = (unsigned char)c;
    __m256i			v = _mm256_set1_epi8(value);
    size_t			offset = (uintptr_t)ptr & (VEC_SIZE - 1);
	
	_mm_prefetch(ptr, _MM_HINT_NTA);
    if (offset) 
    {
        size_t align_size = VEC_SIZE - offset;
        align_size = (align_size > len) ? len : align_size;

        for (size_t i = 0; i < align_size; i++) {
            ptr[i] = value;

		}
			
        ptr += align_size;
        len -= align_size;
		_mm_prefetch(ptr, _MM_HINT_NTA);
		_mm_prefetch(ptr + VEC_SIZE, _MM_HINT_NTA);
	}
	/*
		* chunks is the number of 32 bytes chunks in the memory block.
		* remainings is the number of bytes that are not part of a 32 bytes chunk.
		* The function sets the memory to the value c 32 bytes at a time.
	*/
    size_t		chunks = len / VEC_SIZE;
    size_t		remainings = len % VEC_SIZE;
	/*
		* Prefetch the next 64 bytes to improve performance.
		* The _MM_HINT_NTA hint is used to indicate that the data is not accessed again soon.
		* This hint is useful when the data is not accessed sequentially.
	*/
	_mm_prefetch(ptr + chunks * VEC_SIZE, _MM_HINT_NTA);
    for (size_t i = 0; i < chunks; i++) {
		_mm_prefetch(ptr + (i + 1) * VEC_SIZE, _MM_HINT_NTA);
        _mm256_storeu_si256((__m256i *)(ptr + i * VEC_SIZE), v);
    }

    if (remainings > 0) {
        ptr += chunks * VEC_SIZE;
        for (size_t i = 0; i < remainings; i++) {
            ptr[i] = value;
        }
    }

    return b;
}


	/*
	* The function checks if the Enhanced REP MOVSB/STOSB feature is supported by the CPU.
	* The function returns 1 if the feature is supported, otherwise it returns 0.
	*/

	/*
		* The cpuid instruction is used to get information about the CPU.
		* The function uses the cpuid instruction with the EAX register set to 7 and the ECX register set to 0.
		* The function checks if the Enhanced REP MOVSB/STOSB feature is supported by checking the ninth bit of the ECX register.
		* The function returns 1 if the feature is supported, otherwise it returns 0.
	*/

	/*
	* registers explanation:
	* EAX: The EAX register is used to specify the CPU feature to query.
	* EBX: The EBX register is used to store the second part of the CPU feature information.
	* ECX: The ECX register is used to specify the sub-feature to query.
		* EDX: The EDX register is used to store the first part of the CPU feature information.
	* The function uses the cpuid instruction to get information about the CPU.
	* The function sets the EAX register to 7 and the ECX register to 0.
	* The function uses the cpuid instruction to get the CPU feature information.
	* The function checks if the ninth bit of the ECX register is set.	
	* The function returns 1 if the ninth bit of the ECX register is set, otherwise it returns 0.
	*/
