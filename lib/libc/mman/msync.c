#include <syscall.h>
#include <sys/mman.h>

int msync(void *addr, size_t len, int flags)
{
	return syscall(msync, addr, len, flags);
}
