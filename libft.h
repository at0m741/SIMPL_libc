#pragma once

#include <stdlib.h>
#include <x86intrin.h>
#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

#define AVX2_ALIGNMENT 32
#define AVX2_SIZE 32
#define BLOCK_SIZE 4096
#define CHAR_PER_VEC (AVX2_SIZE / sizeof(char))
#define VEC_SIZE 32
/*
	* check CPU features
*/

#define CHECK_FEATURE(name) { #name, __builtin_cpu_supports(#name) }
typedef struct 
{
    const char *name;
    int supported;
} cpu_feature_t;


int ERMS();
int get_cpu_info();
void check_cpu_features();

#if defined(__CLANG__) || defined(__GNUC__)
    #define __ALIGN(n) __attribute__((aligned(n)))
    #define __ALIGNED(n) __attribute__((aligned(n)))
    #define __RESTRICT __restrict__
    #define __CPU_FEATURES __builtin_cpu_supports
	#if defined(__GNUC__)
		#define __builtin_cpu_supports(name) __builtin_cpu_supports(name)
	#endif
#elif defined(_MSC_VER)
	#define __ALIGN(n) __declspec(align(n))
	#define __ALIGNED(n) __declspec(align(n))
	#define __RESTRICT __restrict
	#define __CPU_FEATURES __cpuid
#endif
/**
    * @brief Compare two strings
    * 
    * @param s1 The first string
    * @param s2 The second string
    * @param n The number of bytes to compare
    * @return int 0 if the strings are equal, otherwise the difference between the first two differing bytes
    
*/
int ft_strncmp(const char *s1, const char *s2, size_t n);
/**
    *@brief get the length of a string
    *@param s The string to get the length of
    *@return size_t The length of the string
    *@note This function is optimized using AVX2 instructions
    *@note if s is NULL, the function will return 0
    *@note if the str is not aligned on a 32 bytes boundary, 
    the function will handle the initial bytes separately 
*/
size_t _strlen(const char *s);
size_t _strlen_avx(const char *s);
size_t _strlen_sse(const char *s);
size_t strlen_sse(const char *s);
size_t ft_strlen_sse_asm(const char *s);
size_t ft_strlen_avx_asm(const char *s);
/**
	*@brief copy n bytes from src to dst
	*@param dst The destination buffer
	*@param src The source buffer
	*@param n The number of bytes to copy
	*@return void* The destination buffer
	*@note This function is optimized using AVX2 instructions
	*@note if dst or src is NULL, the function will return NULL
	*@note if n is 0, the function will return dst
	*@note if the src is not aligned on a 32 bytes boundary, 
	the function will handle the initial bytes separately 
*/
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memcpy_ERMS(void *dest, const void *src, size_t n); 
/**
	*@brief set n bytes of a memory block to a value
	*@param b The memory block
	*@param c The value to set
	*@param len The number of bytes to set
	*@return void* The memory block
	*@note This function is optimized using AVX2 instructions
	*@note if b is NULL, the function will return NULL
	*@note if len is 0, the function will return b
	*@note if the pointer is not aligned on a 32 bytes boundary, 
	the function will handle the initial bytes separately 
*/

/* ERM: Enhanced Rep Movsb */
/* ERM is a feature that allows the REP MOVSB instruction to be faster by using the ERMSB feature. */
void *ft_memset_ERMS(void *b, int c, size_t len);
void *ft_memset(void *b, int c, size_t len);

/**
	* @brief memmove copies n bytes from src to dest
	* @param dest The destination buffer
	* @param src The source buffer
	* @param n The number of bytes to copy
	* @return void* The destination buffer
	* @note This function is optimized using ERMS instructions
	* @note if dest or src is NULL, the function will return NULL
 */
void *ft_memmove_ERMS(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memmove_ERMS_AVX2(void *dest, const void *src, size_t n);
