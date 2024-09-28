#include "misc.h"
#include <sys/stdargs.h>
#include <sys/cdefs.h>
#include <errno.h>

long int __MISC_FUNC(syscall)(long int callno __unused, ...)
{
	__set_errno(1);
	return -1;
}


