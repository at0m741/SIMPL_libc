#include "libmath.h"

/*
	* ft_sqrt_512 that takes a double x as input and returns the square root of x.
* ft_sqrt_256 that takes a double x as input and returns the square root of x.
* ft_sqrt_128 that takes a double x as input and returns the square root of x.
* ft_sqrt_512f that takes a float x as input and returns the square root of x.
* ft_sqrt_256f that takes a float x as input and returns the square root of x.
* ft_sqrt_128f that takes a float x as input and returns the square root of x.
* ft_sqrt_64f that takes a float x as input and returns the square root of x.
*/
/*
	* they are implemented using the sqrtps, sqrtpd, and sqrtsd instructions.
*/
double ft_sqrt_512(double x) {__asm__ __volatile__("sqrtpd %zmm0, %zmm0");}
double ft_sqrt_256(double x) {__asm__ __volatile__("sqrtpd %ymm0, %ymm0");}
double ft_sqrt_128(double x) {__asm__ __volatile__("sqrtpd %xmm0, %xmm0");}
float ft_sqrt_512f(float x) {__asm__ __volatile__("sqrtps %zmm0, %zmm0");}
float ft_sqrt_256f(float x) {__asm__ __volatile__("sqrtps %ymm0, %ymm0");}
float ft_sqrt_128f(float x) {__asm__ __volatile__("sqrtps %xmm0, %xmm0");}
float ft_sqrt_64f(float x) {__asm__ __volatile__("sqrtsd %xmm0, %xmm0");}



