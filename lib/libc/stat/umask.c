#include "asm/unistd_64.h" // for __NR_umask

#include <sys/stat.h>  // for umask
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_1, syscall

mode_t umask(mode_t cmask)
{
	return syscall(umask, cmask);
}
