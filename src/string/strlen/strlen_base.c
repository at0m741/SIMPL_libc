#include <stdint.h>

size_t _strlen_base(const char *s) 
{
	const char *endptr;

	endptr = s;
	while (*endptr)
		endptr++;
	return (endptr - s);
}
