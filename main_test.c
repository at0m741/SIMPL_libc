#include <stdio.h>
#include <string.h>
#include <time.h>

// Déclaration de la fonction ft_strlen_avx
extern size_t ft_strlen_sse(const char *str);
extern size_t ft_strlen_avx(const char *str);
#define NUM_ITERATIONS 100000000

void benchmark_strlen(const char *str) {
    clock_t start, end;
    size_t len;

    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        len = strlen(str);
    }
    end = clock();

    printf("strlen: Length of string \"%s\" is %zu, Time taken: %f seconds\n",
           str, len, ((double)(end - start)) / CLOCKS_PER_SEC);
}

void benchmark_ft_strlen_avx(const char *str) {
    clock_t start, end;
    size_t len;

    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        len = ft_strlen_avx(str);
    }
    end = clock();

    printf("ft_strlen_avx: Length of string \"%s\" is %zu, Time taken: %f seconds\n",
           str, len, ((double)(end - start)) / CLOCKS_PER_SEC);

	start = clock();
	for (int i = 0; i < NUM_ITERATIONS; ++i) {
		len = ft_strlen_sse(str);
	}
	end = clock();

	printf("ft_strlen_sse: Length of string \"%s\" is %zu, Time taken: %f seconds\n",
		   str, len, ((double)(end - start)) / CLOCKS_PER_SEC);
	printf("\n");
	

}

int main() {
    const char *test_strings[] = {
        "",
        "Hello, world!",
        "This is a test string.",
        "AVX is awesome!",
        "A very long string to test the performance of our AVX strlen implementation."
    };

    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < num_tests; ++i) {
        benchmark_strlen(test_strings[i]);
        benchmark_ft_strlen_avx(test_strings[i]);
    }

    return 0;
}

