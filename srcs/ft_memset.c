#include "../libft.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <x86intrin.h>
#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

#define VEC_SIZE 32
#define BLOCK_SIZE 4096

void *ft_memset(void *b, int c, size_t len) 
{
    unsigned char *ptr = (unsigned char *)b;
    unsigned char value = (unsigned char)c;
    __m256i v = _mm256_set1_epi8(value);

    // Handle initial misaligned bytes
    size_t offset = (uintptr_t)ptr & (VEC_SIZE - 1);
    if (offset != 0) 
    {
        size_t align_size = VEC_SIZE - offset;
        align_size = (align_size > len) ? len : align_size;

        for (size_t i = 0; i < align_size; i++) {
            ptr[i] = value;
        }

        ptr += align_size;
        len -= align_size;
    }

    size_t chunks = len / VEC_SIZE;
    size_t remainings = len % VEC_SIZE;

    // Process chunks using AVX2
    for (size_t i = 0; i < chunks; i++) {
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

int main(void)
{
    char str[100] = "Hello, World!";
    ft_memset(str, 'A', 5);
    char str2[100] = "Hello, World!";
    memset(str2, 'A', 5);
    printf("%s\n", str2);
    printf("%s\n", str);
    return 0;
}

