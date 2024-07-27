
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

void _exit(int status) __attribute__((noreturn));

//void _start(void)
//{
//    __asm__ __volatile__
//    (
//        "mov %%rsp, %%rdi\n"			/* set up arguments for main */
//        "lea 8(%%rsp), %%rsi\n"			/* argv  to rsi, why ? because..*/
//        "mov %%rsi, %%rdx\n"			/* envp to rdx, minishell ?*/
//        "add $8, %%rdx\n"				/* like MJ, jump over the envp */		
//        "andq $-16, %%rsp\n"			/* align stack pointer over 16b*/
//        "call main\n"
//        "mov %%rax, %%rdi\n"			/* save return value (yes fuuuuu asm)*/
//        "call exit\n"
//        :
//        :
//        : "rdi", "rsi", "rdx", "rax"	/* clobbered registers used over*/
//    );
//}


void _exit(int status)
{
	__asm__ __volatile__ (
		"mov $60, %%rax\n\t"   // syscall number for exit
		"mov %0, %%rdi\n\t"    // move status into rdi
		"syscall\n\t"
		:
		: "r" ((long)status)
		: "rax", "rdi"
	);

	while (1);
}

libft_weak_alias(exit, _exit)

typedef int (*main_func)(int, char**, char**);

int __libc_start_main(main_func main, int argc, char** argv, char** envp) {
    int exit_status = main(argc, argv, envp);

	// get aux data after env (aux size 38)
	// hwcap in aux (cpu info (could have avx sse data but less precise use in musl for threard data))
	// libc page size in aux
	// sysinfo in aux
	// name program in aux (sure to be there compared to in argv[0]) for debug logging error reporting (perror) and the posix norm
    exit(exit_status);
    return exit_status;
}
