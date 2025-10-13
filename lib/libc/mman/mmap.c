#include <stddef.h>
#include <linux/mman.h>
#include <syscall.h>

typedef __INT64_TYPE__ off_t;

void *mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off)
{
	return (void *)syscall(mmap, addr, len, prot, flags, fildes, off);
}
