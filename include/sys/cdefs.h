#ifndef __CDEFS_H__
#define __CDEFS_H__

#if defined(__linux__)
#define __unused __attribute__((unused))
#else
#define __unused
#endif

#endif /* __CDEFS_H__ */
