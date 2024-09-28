#include <unistd.h>
#include <config.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

simpl_weak_alias(putchar, _putchar)
