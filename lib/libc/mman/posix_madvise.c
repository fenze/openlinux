#include <sys/mman.h>
#include <syscall.h>

int posix_madvise(void *addr, size_t len, int advice)
{
	return syscall(madvise, addr, len, advice);
}
