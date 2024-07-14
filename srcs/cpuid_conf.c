#include <cpuid.h>
#include <stdio.h>

#include "cpuid_conf.h"

simd_support_t simd_support;

static simd_support_t detect_cpu_features() {
  unsigned int eax, ebx, ecx, edx;

	
	simd_support.cpu_id = 0;
  // CPUID with EAX=1: Processor Info and Feature Bits
  if (__get_cpuid(1, &eax, &ebx, &ecx, &edx)) {
    simd_support.mmx = edx & bit_MMX ? 1 : 0;
    simd_support.sse = edx & bit_SSE ? 1 : 0;
    simd_support.sse2 = edx & bit_SSE2 ? 1 : 0;
    simd_support.sse3 = ecx & bit_SSE3 ? 1 : 0;
    simd_support.ssse3 = ecx & bit_SSSE3 ? 1 : 0;
    simd_support.sse41 = ecx & bit_SSE4_1 ? 1 : 0;
    simd_support.sse42 = ecx & bit_SSE4_2 ? 1 : 0;
    simd_support.avx = ecx & bit_AVX ? 1 : 0;
  }

  // CPUID with EAX=7, ECX=0: Extended Features
  if (__get_cpuid_count(7, 0, &eax, &ebx, &ecx, &edx)) {
    simd_support.avx2 = ebx & bit_AVX2 ? 1 : 0;
    simd_support.avx512f = ebx & bit_AVX512F ? 1 : 0;
    simd_support.avx512dq = ebx & bit_AVX512DQ ? 1 : 0;
    simd_support.avx512ifma = ebx & bit_AVX512IFMA ? 1 : 0;
    simd_support.avx512pf = ebx & bit_AVX512PF ? 1 : 0;
    simd_support.avx512er = ebx & bit_AVX512ER ? 1 : 0;
    simd_support.avx512cd = ebx & bit_AVX512CD ? 1 : 0;
    simd_support.avx512bw = ebx & bit_AVX512BW ? 1 : 0;
    simd_support.avx512vl = ebx & bit_AVX512VL ? 1 : 0;
  }

  return simd_support;
}

void print_features() {

	printf("simd support %d\n", simd_support.cpu_id);
  if (simd_support.mmx) printf("-mmmx ");
  if (simd_support.sse) printf("-msse ");
  if (simd_support.sse2) printf("-msse2 ");
  if (simd_support.sse3) printf("-msse3 ");
  if (simd_support.ssse3) printf("-mssse3 ");
  if (simd_support.sse41) printf("-msse4.1 ");
  if (simd_support.sse42) printf("-msse4.2 ");
  if (simd_support.avx) printf("-mavx ");
  if (simd_support.avx2) printf("-mavx2 ");
  if (simd_support.avx512f) printf("-mavx512f ");
  if (simd_support.avx512dq) printf("-mavx512dq ");
  if (simd_support.avx512ifma) printf("-mavx512ifma ");
  if (simd_support.avx512pf) printf("-mavx512pf ");
  if (simd_support.avx512er) printf("-mavx512er ");
  if (simd_support.avx512cd) printf("-mavx512cd ");
  if (simd_support.avx512bw) printf("-mavx512bw ");
  if (simd_support.avx512vl) printf("-mavx512vl ");

  printf("\n");
}

void __attribute__((constructor)) init_simd_support(void) {
  detect_cpu_features();
#ifdef VERBOSE
  print_features();
#endif
}
