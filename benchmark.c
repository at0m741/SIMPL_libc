#include <time.h>
#include "libft.h"

void benchmark(size_t size, size_t iterations) {
    void *src = aligned_alloc(32, size);
    void *dest1 = aligned_alloc(32, size);
    void *dest2 = aligned_alloc(32, size);

    if (!src || !dest1 || !dest2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < size; i++) {
        ((char*)src)[i] = rand() % 256;
    }

    struct timespec start, end;
    double cpu_time_used;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
        ft_memmove_ERMS_AVX2(dest1, src, size);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("ft_memmove_ERMS_AVX2: %f seconds\n", cpu_time_used);

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
        memmove(dest2, src, size);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("standard memmove: %f seconds\n", cpu_time_used);

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
        ft_memmove(dest2, src, size);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("ft_memmove: %f seconds\n", cpu_time_used);

    if (memcmp(dest1, dest2, size) != 0) {
        fprintf(stderr, "Error: Memory contents differ after memmove\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
        ft_memset(dest1, 0, size);
    }
	printf("\n--------------------------------------\n\n");
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("ft_memset: %f seconds\n", cpu_time_used);

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
        memset(dest2, 0, size);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("standard memset: %f seconds\n", cpu_time_used);

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iterations; i++) {
		ft_memset_ERMS(dest1, 0, size);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("ft_memset_ERMS: %f seconds\n", cpu_time_used);

    free(src);
    free(dest1);
    free(dest2);
}

void bench_strlen(size_t iter)
{
	const char *str = "Hello, Wodjasldjasldjaskdlasdasdasdlkaslldakjsdklarld!";
	size_t len;

	struct timespec start, end;
	double cpu_time_used;

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iter; i++) {
		len = ft_strlen(str);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("ft_strlen: %f seconds\n", cpu_time_used);
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iter; i++) {
		len = ft_strlen_avx(str);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("ft_strlen_avx: %f seconds\n", cpu_time_used);

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iter; i++) {
		len = ft_strlen_sse(str);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("ft_strlen_sse: %f seconds\n", cpu_time_used);

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iter; i++) {
		len = strlen(str);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("standard strlen: %f seconds\n", cpu_time_used);
}

int main() {
    size_t size = 1024 * 1024; // 1 MB
    size_t iterations = 100000;

    benchmark(size, iterations);
	printf("\n--------------------------------------\n\n");
	bench_strlen(iterations);

    return 0;
}
