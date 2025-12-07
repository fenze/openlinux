#include <syscall.h>
#include <sys/mman.h>

int mlock(const void *addr, size_t len)
{
	return syscall(mlock, addr, len);
}
