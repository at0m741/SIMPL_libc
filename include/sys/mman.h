#ifndef MMAN_H
# define MMAN_H


/* void	*ft_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset); */
/* int		ft_munmap(void *addr, size_t length); */
/* int	ft_mprotect(void *addr, size_t len, int prot); */

# define PROT_NONE 0x0
# define PROT_READ 0x1
# define PROT_WRITE 0x2
# define PROT_RW (PROT_WRITE | PROT_READ)

# define MAP_PRIVATE 0x02
# define MAP_ANONYMOUS 0x20
#define MAP_FAILED        ((void *) -1)

#endif /* MMAN_H */
