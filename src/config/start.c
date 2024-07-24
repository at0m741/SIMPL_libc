#include <config.h>

int main(int argc, char **argv, char **envp);

/* _start is the entry point of this new libc */
void _start(void) __attribute__((naked));

/* exit function to terminate the program */
void exit(int status) __attribute__((noreturn));

void _start(void)
{
    __asm__ __volatile__
    (
        "xor %%ebp, %%ebp\n"            /* Clear the base pointer */
        "mov %%rdx, %%r9\n"             /* Move the third argument to r9 */
        "pop %%rsi\n"                   /* Pop the return address to rsi (argv) */
        "mov %%rsp, %%rdx\n"            /* Move stack pointer to rdx (envp) */
        "andq $-16, %%rsp\n"            /* Align stack pointer to 16-byte boundary */
        "mov $0, %%r8\n"                /* Zero out r8 */
        "call __libc_start_main\n"      /* Call __libc_start_main */
        :
        :
        : "rdi", "rsi", "rdx", "rcx", "r9", "r8"  /* Indicate which registers are clobbered */
    );
}

/* exit implementation */
void exit(int status)
{
    __asm__ __volatile__
    (
        "movl $60, %%eax\n"             /* syscall number for exit is 60 */
        "movl %0, %%edi\n"              /* Move the status into edi */
        "syscall\n"                     /* Execute the syscall */
        :
        : "r" (status)
        : "rax", "rdi"                  /* Indicate which registers are clobbered */
    );

    while (1);  /* Ensure the function does not return */
}

/* __libc_start_main implementation */
typedef int (*main_func)(int, char**, char**);

int __libc_start_main(main_func main, int argc, char** argv, char** envp) 
{
    int exit_status = main(argc, argv, envp);
    exit(exit_status);
    return exit_status;  /* This line will never be reached */
}
