

#include <stddef.h>
#include <sys/mman.h> // for posix_madvise, size_t
#include <syscall.h>  // for __syscall_3, syscall

int posix_madvise(void *addr, size_t len, int advice)
{
	return syscall(madvise, addr, len, advice);
}
