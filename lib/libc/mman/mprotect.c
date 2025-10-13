#include <syscall.h>
#include <sys/mman.h>

int mprotect(void *addr, size_t len, int prot)
{
	return syscall(mprotect, addr, len, prot);
}
