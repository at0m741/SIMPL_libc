#include <config.h>

int main(int argc, char **argv, char **envp);

/* _start is the entry point of this new libc */
void _start(void) __attribute__((naked));

void exit(int status) __attribute__((noreturn));

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
    __asm__ __volatile__
    (
		".intel_syntax noprefix\n"
        "mov rax, 60\n"                 /* syscall number for exit */
		"mov rdi, 0\n"                 /* status */
		"syscall\n"                     /* make the syscall */
		:
		: "g" (status)
		: "rax", "rdi"
	);

    while (1);  /* Ensure the function does not return */
}


libft_weak_alias(exit, _exit)


typedef int lsm2_fn(int (*) (int, char **, char **), int, char **, char **);


//void _start(void)
//{
//    __asm__ __volatile__
//    (
//        "xor %%ebp, %%ebp\n"            /* Clear the base pointer */
//        "mov %%rdx, %%r9\n"             /* Move the third argument to r9 */
//        "pop %%rsi\n"                   /* Pop the return address to rsi (argv) */
//        "mov %%rsp, %%rdx\n"            /* Move stack pointer to rdx (envp) */
//        "andq $-16, %%rsp\n"            /* Align stack pointer to 16-byte boundary */
//        "mov $0, %%r8\n"                /* Zero out r8 */
//		"mov %%rsp, %%rdi\n"            /* Move stack pointer to rdi (argc) */
//		"call _start\n"                 /* Call _start */
//		"call __libc_start_main\n"      /* Call __libc_start_main */
//        :
//        :
//        : "rdi", "rsi", "rdx", "rcx", "r9", "r8"  /* Indicate which registers are clobbered */
//    );
//}


/* __libc_start_main implementation */
typedef int (*main_func)(int, char**, char**);

int __libc_start_main(main_func main, int argc, char** argv, char** envp) 
{
    int exit_status = main(argc, argv, envp);
    exit(exit_status);
    return exit_status;  /* This line will never be reached */
}


/*  */
/* int __libc_start_main(main_func main, int argc, char** argv, char** envp) { */
/*     int exit_status = main(argc, argv, envp); */
/*  */
/* 	// get aux data after env (aux size 38) */
/* 	// hwcap in aux (cpu info (could have avx sse data but less precise use in musl for threard data)) */
/* 	// libc page size in aux */
/* 	// sysinfo in aux */
/* 	// name program in aux (sure to be there compared to in argv[0]) for debug logging error reporting (perror) and the posix norm */
/*     exit(exit_status); */
/*     return exit_status; */
/* } */
