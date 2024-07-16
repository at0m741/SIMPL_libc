
#include <config.h>

/*
	* _start is the entry point of this new libc
	* this is the first function called by this libc (optimized with love by babonnet and ltouzali)
	* it's a main that calls the real main yes it's a main that calls the real main main in a main for the main, u kno budy ????!!!!!!!!
*/

int main(int argc, char **argv, char **envp);

void _start(void) __attribute__((naked));

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

