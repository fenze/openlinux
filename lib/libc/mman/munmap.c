#include "asm/unistd_64.h" // for __NR_munmap

#include <sys/mman.h> // for munmap, size_t
#include <syscall.h>  // for __syscall_2, syscall

int munmap(void *addr, size_t len)
{
	return syscall(munmap, addr, len);
}
