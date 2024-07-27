#ifndef PTRACE_H
#define PTRACE_H

#include <config.h>

#define PTRACE_INIT 0x101
#define PTRACE_DEINIT 0x102
#define PTRACE 0x103
#define PTRACE_GETREGS 0x104
#define PTRACE_SETREGS 0x105
#define PTRACE_GETFPREGS 0x106
#define PTRACE_SETFPREGS 0x107
#define PTRACE_GETREGSET 0x108
#define PTRACE_SETREGSET 0x109
#define PTRACE_SYSCALL 0x110
#define PTRACE_SINGLESTEP 0x111
#define PTRACE_CONT 0x112



void _ptrace_init(void);
void _ptrace_deinit(void);
long _ptrace(int request, int pid, void *addr, void *data);


#endif // PTRACE_H
