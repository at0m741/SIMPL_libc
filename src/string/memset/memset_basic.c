#include <stdint.h>

void	*_memset_base(void *s, int c, size_t n)
{
	uint8_t	*ptr;

	if (s)
	{
		ptr = (uint8_t *)s;
		while (n--)
			*ptr++ = c;
	}
	return (s);
}
