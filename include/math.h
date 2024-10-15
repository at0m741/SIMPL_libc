#ifndef _MATH_H
#define _MATH_H

#include <stddef.h>
#include <stdint.h>


#define NAN __builtin_nan("")
#define INFINITY __builtin_inf()

#define HUGE_VAL __builtin_huge_val()
#define HUGE_VALF __builtin_huge_valf()

#define M_E 2.7182818284590452354
#define M_LOG2E 1.4426950408889634074
#define M_LOG10E 0.43429448190325182765
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.78539816339744830962
#define M_1_PI 0.31830988618379067154
#define M_2_PI 0.63661977236758134308
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2 1.41421356237309504880
#define M_SQRT1_2 0.70710678118654752440

#define isinf(x) { __builtin_isinf_signbit(x) ? 1 : 0; }
#define isnan(x) { __builtin_isnan(x) ? 1 : 0; }
#define isfinite(x) { __builtin_isfinite(x) ? 1 : 0; }

#endif /* _MATH_H */
