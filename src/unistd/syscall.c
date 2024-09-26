#include <config.h>

#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>

long _syscall(long number, ...) {
    va_list args;
    va_start(args, number);

    unsigned long arg1 = va_arg(args, unsigned long);
    unsigned long arg2 = va_arg(args, unsigned long);
    unsigned long arg3 = va_arg(args, unsigned long);
    unsigned long arg4 = va_arg(args, unsigned long);
    unsigned long arg5 = va_arg(args, unsigned long);
    unsigned long arg6 = va_arg(args, unsigned long);

    va_end(args);

    long ret;

    __asm__ volatile (
        "mov %1, %%rax \n"
        "mov %2, %%rdi \n" 
        "mov %3, %%rsi \n" 
        "mov %4, %%rdx \n" 
        "mov %5, %%r10 \n" 
        "mov %6, %%r8  \n" 
        "mov %7, %%r9  \n" 
        "syscall        \n" 
        "mov %%rax, %0  \n" 
        : "=r" (ret) 
        : "r" (number),  
          "r" (arg1),
          "r" (arg2),
          "r" (arg3),
          "r" (arg4),
          "r" (arg5),
          "r" (arg6)
        : "%rax", "%rdi", "%rsi", "%rdx", "%r10", "%r8", "%r9", "memory"
    );

    if (ret < 0) {
        return ret;
    }

    return ret;
}
