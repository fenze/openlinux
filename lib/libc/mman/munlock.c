#include <syscall.h>
#include <sys/mman.h>

int munlock(const void *addr, size_t len)
{
	return syscall(munlock, addr, len);
}
