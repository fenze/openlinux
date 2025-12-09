


#include <stddef.h>  // for size_t
#include <syscall.h> // for __syscall_2, syscall

int munlock(const void *addr, size_t len)
{
	return syscall(munlock, addr, len);
}
