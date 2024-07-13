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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double benchmark(void *(*memmove_func)(void *, const void *, size_t), void *dest, const void *src, size_t n) {
    clock_t start = clock();
    memmove_func(dest, src, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    size_t sizes[] = {1024, 4096, 16384, 65536, 26214434};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        size_t size = sizes[i];
        char *src = (char *)malloc(size);
        char *dest_std = (char *)malloc(size);
        char *dest_opt = (char *)malloc(size);

        if (src == NULL || dest_std == NULL || dest_opt == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return EXIT_FAILURE;
        }

        for (size_t j = 0; j < size; j++) {
            src[j] = (char)(j % 256);
        }

        double time_std = benchmark(memmove, dest_std, src, size);
        printf("Standard memmove: %zu bytes in %f seconds\n", size, time_std);
        double time_opt = benchmark(ft_memmove, dest_opt, src, size);
        printf("Optimized memmove: %zu bytes in %f seconds\n", size, time_opt);

        free(src);
        free(dest_std);
        free(dest_opt);
    }

    return EXIT_SUCCESS;
}
