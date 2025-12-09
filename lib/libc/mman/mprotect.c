


#include <stddef.h>  // for size_t
#include <syscall.h> // for __syscall_3, syscall

int mprotect(void *addr, size_t len, int prot)
{
	return syscall(mprotect, addr, len, prot);
}
