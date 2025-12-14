

#include <stddef.h>  // for size_t
#include <syscall.h> // for __syscall_6, syscall

typedef __INT64_TYPE__ off_t;

void *mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off)
{
	return (void *)syscall(mmap, addr, len, prot, flags, fildes, off);
}
