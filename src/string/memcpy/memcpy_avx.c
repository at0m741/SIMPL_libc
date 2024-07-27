#include <stdint.h>
#include <immintrin.h>
#include <stdlib.h>
#include "../../libft.h"
/*
 *  this implementation of the memcpy function using AVX2 instructions
 *  less instruction, less cache misses, less branch mispredictions
*/

	/*
		* handle the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
		* load 32 bytes from the memory pointed by s and store them in the memory pointed by d.
		* prefetch the next 32 bytes to improve performance.
	*/

/*
		* chunks is the number of 32 bytes chunks in the memory block.
		* remaining_bytes is the number of bytes that are not part of a 32 bytes chunk.
		* The function copies the memory 32 bytes at a time.
		* The function uses prefetching to improve performance.
	*/



void *_memcpy_avx(void *dest, const void *src, size_t n) 
{
    void *ret = dest;

    uintptr_t dest_ptr = (uintptr_t)dest;
    uintptr_t src_ptr = (uintptr_t)src;

    while (dest_ptr % 32 != 0 && n > 0) {
        *(char *)dest_ptr = *(const char *)src_ptr;
        dest_ptr++;
        src_ptr++;
        n--;
    }

	if (n <= 16) {
		__m128i data = _mm_loadu_si128((const __m128i *)(src_ptr));
		_mm_storeu_si128((__m128i *)(dest_ptr), data);
		return ret;
	}

    while (n >= 32) {
        __m256i data = _mm256_loadu_si256((const __m256i *)(src_ptr));
        _mm256_storeu_si256((__m256i *)(dest_ptr), data);
        src_ptr += 32;
        dest_ptr += 32;
        n -= 32;
    }

	if (n >= 64) {
		__m256i data1 = _mm256_loadu_si256((const __m256i *)(src_ptr));
		_mm256_storeu_si256((__m256i *)(dest_ptr), data1);
		src_ptr += 64;
		dest_ptr += 64;
		_mm_prefetch((const char *)(src_ptr), _MM_HINT_T0);
		__m256i data2 = _mm256_loadu_si256((const __m256i *)(src_ptr));
		_mm256_storeu_si256((__m256i *)(dest_ptr), data2);
		return ret;
	} 

	if (n >= 512 && n <= 2048) {
		while (n >= 512) {
			_mm_prefetch((const char *)(src_ptr + 512), _MM_HINT_T0);
			__m256i data1 = _mm256_loadu_si256((const __m256i *)(src_ptr));
			__m256i data2 = _mm256_loadu_si256((const __m256i *)(src_ptr + 32));
			__m256i data3 = _mm256_loadu_si256((const __m256i *)(src_ptr + 64));
			__m256i data4 = _mm256_loadu_si256((const __m256i *)(src_ptr + 96));
			__m256i data5 = _mm256_loadu_si256((const __m256i *)(src_ptr + 128));
			__m256i data6 = _mm256_loadu_si256((const __m256i *)(src_ptr + 160));
			__m256i data7 = _mm256_loadu_si256((const __m256i *)(src_ptr + 192));
			__m256i data8 = _mm256_loadu_si256((const __m256i *)(src_ptr + 224));
			__m256i data9 = _mm256_loadu_si256((const __m256i *)(src_ptr + 256));
			__m256i data10 = _mm256_loadu_si256((const __m256i *)(src_ptr + 288));
			__m256i data11 = _mm256_loadu_si256((const __m256i *)(src_ptr + 320));
			__m256i data12 = _mm256_loadu_si256((const __m256i *)(src_ptr + 352));
			__m256i data13 = _mm256_loadu_si256((const __m256i *)(src_ptr + 384));
			__m256i data14 = _mm256_loadu_si256((const __m256i *)(src_ptr + 416));
			__m256i data15 = _mm256_loadu_si256((const __m256i *)(src_ptr + 448));
			__m256i data16 = _mm256_loadu_si256((const __m256i *)(src_ptr + 480));
			_mm256_storeu_si256((__m256i *)(dest_ptr), data1);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 32), data2);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 64), data3);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 96), data4);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 128), data5);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 160), data6);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 192), data7);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 224), data8);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 256), data9);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 288), data10);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 320), data11);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 352), data12);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 384), data13);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 416), data14);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 448), data15);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 480), data16);
			src_ptr += 512;
			dest_ptr += 512;
			n -= 512;
		}
	}

	_mm_prefetch((const char *)(src_ptr), _MM_HINT_T0);
    if (n >= 4096) {
		while (n >= 4096) {
			_mm_prefetch((const char *)(src_ptr + 512), _MM_HINT_T0);
			__m256i data1 = _mm256_loadu_si256((const __m256i *)(src_ptr));
			__m256i data2 = _mm256_loadu_si256((const __m256i *)(src_ptr + 32));
			__m256i data3 = _mm256_loadu_si256((const __m256i *)(src_ptr + 64));
			__m256i data4 = _mm256_loadu_si256((const __m256i *)(src_ptr + 96));
			__m256i data5 = _mm256_loadu_si256((const __m256i *)(src_ptr + 128));
			__m256i data6 = _mm256_loadu_si256((const __m256i *)(src_ptr + 160));
			__m256i data7 = _mm256_loadu_si256((const __m256i *)(src_ptr + 192));
			__m256i data8 = _mm256_loadu_si256((const __m256i *)(src_ptr + 224));
			__m256i data9 = _mm256_loadu_si256((const __m256i *)(src_ptr + 256));
			__m256i data10 = _mm256_loadu_si256((const __m256i *)(src_ptr + 288));
			__m256i data11 = _mm256_loadu_si256((const __m256i *)(src_ptr + 320));
			__m256i data12 = _mm256_loadu_si256((const __m256i *)(src_ptr + 352));
			__m256i data13 = _mm256_loadu_si256((const __m256i *)(src_ptr + 384));
			__m256i data14 = _mm256_loadu_si256((const __m256i *)(src_ptr + 416));
			__m256i data15 = _mm256_loadu_si256((const __m256i *)(src_ptr + 448));
			__m256i data16 = _mm256_loadu_si256((const __m256i *)(src_ptr + 480));
			_mm256_storeu_si256((__m256i *)(dest_ptr), data1);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 32), data2);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 64), data3);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 96), data4);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 128), data5);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 160), data6);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 192), data7);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 224), data8);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 256), data9);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 288), data10);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 320), data11);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 352), data12);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 384), data13);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 416), data14);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 448), data15);
			_mm256_storeu_si256((__m256i *)(dest_ptr + 480), data16);
			src_ptr += 512;
			dest_ptr += 512;
			n -= 512;
		}
	}
	while (n > 0) {
        *(char *)dest_ptr = *(const char *)src_ptr;
        dest_ptr++;
        src_ptr++;
        n--;
    }

    return ret;
}

