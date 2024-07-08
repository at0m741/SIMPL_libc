#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <x86intrin.h>
#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

#define AVX2_ALIGNMENT 32
#define AVX2_SIZE 32
#define BLOCK_SIZE 4096
#define CHAR_PER_VEC (AVX2_SIZE / sizeof(char))
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
    *@brief check if the vector v contains a zero byte
    *@param v The vector to check
    *@return int 0 if no zero byte is found, otherwise return a non-zero value
*/
static inline int has_zero_byte(__m256i v);
/**
    *@brief get the length of a string
    *@param s The string to get the length of
    *@return size_t The length of the string
    *@note This function is optimized using AVX2 instructions
    *@note if s is NULL, the function will return 0
    *@note if the str is not aligned on a 32 bytes boundary, 
    the function will handle the initial bytes separately 
*/
size_t ft_strlen(const char *s);


