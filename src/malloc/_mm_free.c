#include "malloc.h"

/* void _mm_free(void *ptr) { */
/* 	if (ptr) { */
/* 		void *allocated_mem = ((void**)ptr)[-1]; */
/* 		size_t total_size = ((size_t*)ptr)[-2] + sizeof(void*) + sizeof(size_t); */
/* 		_munmap(allocated_mem, total_size); */
/* 	} */
/* } */
