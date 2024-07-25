#include <config.h>

/* mmap syscall */
/* 
 * void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
 * 
 * addr: starting address of the memory region to be mapped
 * length: length of the memory region to be mapped
 * prot: protection flags
 * flags: mapping flags
 * fd: file descriptor
 * offset: offset in the file
 * 
 * return value: starting address of the mapped memory region
 * 
 * This function maps a memory region of length length starting from addr.
 * The memory region is mapped with the protection flags prot and mapping flags flags.
 * If fd is not -1, the memory region is mapped from the file with file descriptor fd starting from offset.
 * 
 * If the function fails, it returns MAP_FAILED.
 */

#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4

#define MAP_PRIVATE 0x02
#define MAP_ANONYMOUS 0x20
#define MAP_FAILED ((void *)-1)

#define MAP_FIXED 0x10


void* _mmap(void* start, size_t len, int prot, int flags, int fd, size_t offset) {
    if (!len || !prot) {
        return MAP_FAILED;
    }

	/* check if the start address is NULL */
	/* if it is, set the start address to 0 */
	if (!start) {
		start = 0;
	}
	/* these registers are used to pass the arguments to the syscall */
	/* make the mmap syscall */

    void* result;
    register uint64_t r10 asm("r10") = flags;
    register uint64_t r8 asm("r8") = fd;
    register uint64_t r9 asm("r9") = offset;

	/* make mmap syscall */
	/* rax = 0x9, syscall number of mmap */
	/* rdi = start, starting address of the memory region to be mapped */
	/* rsi = len, length of the memory region to be mapped */
	/* rdx = prot, protection flags */
	/* r10 = flags, mapping flags */
	/* r8 = fd, file descriptor */
	/* r9 = offset, offset in the file */
	/* syscall, result is stored in rax */
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n"
        "mov rax, 0x9\n"                   
        "syscall\n"
	  : "=a"(result)           
	  : "D"(start)	, "S"(len),
	    "d"(prot)	, "r"(r10), 
     	"r"(r8)		, "r"(r9)
      : "memory", 
		"rcx", 
		"r11"
    );

	/* check if the result is negative */
	/* if it is, return MAP_FAILED */

    if ((uint64_t)result >= (uint64_t)-4095) {
        return MAP_FAILED;
    }

    return result;
}

/* munmap syscall */
/* 
 * int munmap(void *addr, size_t length);
 * 
 * addr: starting address of the memory region to be unmapped
 * length: length of the memory region to be unmapped
 * 
 * return value: 0 on success, -1 on failure
 * 
 * This function unmaps the memory region of length length starting from addr.
 */


void* my_munmap(void* addr, size_t length) {
    if (!length) {
        return MAP_FAILED;
    }

    void* result;
	
	/* make munmap syscall */
	/* rax = 0xb, syscall number of munmap */
	/* rdi = addr, starting address of the memory region to be unmapped */
	/* rsi = length, length of the memory region to be unmapped */
	/* syscall, result is stored in rax */

    __asm__ __volatile__ (
        ".intel_syntax noprefix\n"
        "mov rax, 0xb\n"
        "syscall\n"
        : "=a"(result)
        : "D"(addr), "S"(length)
        : "memory", "rcx", "r11"
    );

    if ((uint64_t)result >= (uint64_t)-4095) {
        return MAP_FAILED;
    }

    return result;
}

