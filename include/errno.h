#ifndef __ERRNO_H__
#define __ERRNO_H__

/* need to be change !!!!!!!!!!!!!!!!!! */
int errno = 0;

int *__get_errno_location(void) { return &errno; }

#define __set_errno(value) (*__get_errno_location() = value)

#endif /* __ERRNO_H__ */
