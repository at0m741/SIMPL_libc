//clang  -nodefaultlibs -o myprogram  libc_avx.so main.c -lc

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <immintrin.h>
#include <stdlib.h>
#include <stdint.h>

// Déclaration de la fonction _strlen_avx
extern size_t _strlen_sse(const char *str);
extern size_t _strlen_avx(const char *str);
#define NUM_ITERATIONS 1

void benchmark_strlen(const char *str) {
    size_t len;

    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        len = strlen(str);
    }
	printf("len = %d\n", len);
}

void benchmark_ft_strlen_avx(const char *str) {
    size_t len;

    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        len = _strlen_avx(str);
    }
	printf("len = %d\n", len);
	for (int i = 0; i < NUM_ITERATIONS; ++i) {
		len = _strlen_sse(str);
	}
	printf("len = %d\n", len);
	printf("\n");
	

}

extern void *_malloc(size_t size);
extern void _free(void *ptr);


char *ft_strdup(const char *s) {
	size_t len = _strlen_avx(s);
	char *new_str = (char *)_malloc(len + 1);
	if (new_str == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < len; ++i) {
		new_str[i] = s[i];
	}
	new_str[len] = '\0';

	return new_str;
}

int main() {
    const char *test_strings[] = {
        "",
        "Hello, world!",
        "This is a test string.",
        "AVX is awesome!",
        "A very long string to test the performance of our AVX strlen implementation."
    };
	
	char *str = ft_strdup("Hello, world!");
	printf("str = %s\n", str);
    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < num_tests; ++i) {
        benchmark_strlen(test_strings[i]);
        benchmark_ft_strlen_avx(test_strings[i]);
    }

	_free(str);
    return 0;
}
