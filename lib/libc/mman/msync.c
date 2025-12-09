


#include <stddef.h>  // for size_t
#include <syscall.h> // for __syscall_3, syscall

int msync(void *addr, size_t len, int flags)
{
	return syscall(msync, addr, len, flags);
}
