
#include <config.h>

/*
	* _start is the entry point of this new libc
	* this is the first function called by this libc (optimized with love by babonnet and ltouzali)
	* it's a main that calls the real main yes it's a main that calls the real main main in a main for the main, u know budy ????!!!!!!!!
*/

/*
	* _exit is the function called when the main returns
	* it's a syscall to exit the program
*/

int main(int argc, char **argv, char **envp);

void _start(void) __attribute__((naked));

void exit(int status) __attribute__((noreturn));

void _start(void)
{
    __asm__ __volatile__
    (
        "mov %%rsp, %%rdi\n"			/* set up arguments for main */
        "lea 8(%%rsp), %%rsi\n"			/* argv  to rsi, why ? because..*/
        "mov %%rsi, %%rdx\n"			/* envp to rdx, minishell ?*/
        "add $8, %%rdx\n"				/* like MJ, jump over the envp */		
        "andq $-16, %%rsp\n"			/* align stack pointer over 16b*/
        "call main\n"
        "mov %%rax, %%rdi\n"			/* save return value (yes fuuuuu asm)*/
        "call exit\n"
        :
        :
        : "rdi", "rsi", "rdx", "rax"	/* clobbered registers used over*/
    );
}

void exit(int status)
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


typedef int (*main_func)(int, char**, char**);

// Minimal prototype of __libc_start_main
int __libc_start_main(main_func main, int argc, char** argv, char** envp) {
    // Call main directly with provided arguments
    int exit_status = main(argc, argv, envp);

    // Terminate the program
    exit(exit_status); // Replace with a syscall or appropriate exit mechanism

    // Normally __libc_start_main should not return
    return exit_status; // This line is effectively never reached
}
