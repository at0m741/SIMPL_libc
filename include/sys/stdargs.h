#ifndef __STDARGS_H__
#define __STDARGS_H__

typedef __builtin_va_list va_list;

#define _va_start(ap, last) __builtin_va_start(ap, last)
#define _va_arg(ap, type) __builtin_va_arg(ap, type)
#define _va_end(ap) __builtin_va_end(ap)

#define _va_copy(dest, src) __builtin_va_copy(dest, src)

typedef __builtin_va_list __gnuc_va_list;

#endif // STDARGS_H
