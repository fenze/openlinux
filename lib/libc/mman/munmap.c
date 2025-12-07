#include <sys/mman.h>
#include <syscall.h>
#include <features.h>

int munmap(void *addr, size_t len)
{
	return syscall(munmap, addr, len);
}
