#include "../libft.h"

#define VEC_SIZE 32
#define BLOCK_SIZE 4096

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

inline void *ft_memset(void *b, int c, size_t len) 
{
    unsigned char *ptr = (unsigned char *)b;
    unsigned char value = (unsigned char)c;
    __m256i v = _mm256_set1_epi8(value);
	_mm_prefetch(ptr, _MM_HINT_NTA);
    size_t offset = (uintptr_t)ptr & (VEC_SIZE - 1);
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

    size_t chunks = len / VEC_SIZE;
    size_t remainings = len % VEC_SIZE;

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

