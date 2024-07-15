#ifndef __LOG_HEADER_H__
#define __LOG_HEADER_H__

#ifdef VERBOSE
#define TOSTRING(x) #x
#define LOG_HEADER(file) _Pragma(TOSTRING(message("Using ftlibc " file)))
#endif

#endif
