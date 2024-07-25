#include <stdint.h>
#include <stdlib.h>

void	*_memcpy_base(void *destination, const void *source, size_t num)
{
	unsigned char	*src;
	unsigned char	*dest;

	src = (unsigned char *) source;
	dest = (unsigned char *) destination;
	if (src == NULL && dest == NULL)
		return (destination);
	while (num--)
		*dest++ = *src++;
	return (destination);
}
