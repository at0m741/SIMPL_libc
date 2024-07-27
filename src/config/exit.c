void _exit(int status)
{
	__asm__ __volatile__
	(
		"movl $60, %%eax\n"				/* syscall exit (code is 60) */
		"movl %0, %%edi\n"				/* status to edi */
		"syscall\n"						/* call the exit syscall */
		:
		: "r" (status)
		: "rax", "rdi"					/* clobbered registers used over */
	);

	while (1);

}
