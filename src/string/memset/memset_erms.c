/*
	* explanation:
* MOVSB copies a byte from the memory location pointed by the DS:SI registers to the memory location pointed by the ES:DI registers.
* REP repeats the MOVSB instruction CX times.
* The function uses the REP STOSB instruction to set the memory pointed by b to the value c.
* The function uses the Enhanced REP MOVSB/STOSB feature if it is supported by the CPU.
* The function uses the regular memset function if the Enhanced REP MOVSB/STOSB feature is not supported by the CPU.
* The function returns the pointer to the memory block.
*/

#include <stdint.h>

void *_memset_erms(void *b, int c, size_t len) 
{
	__asm__ __volatile__ (
		"rep stosb"
		: "+D"(b), "+c"(len)
		: "a"(c)
		: "memory"
	);	
	return b;
}
