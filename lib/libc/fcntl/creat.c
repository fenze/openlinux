#include "asm/unistd_64.h" // for __NR_creat

#include <fcntl.h>     // for creat
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_2, syscall

int creat(const char *path, mode_t mode)
{
	return syscall(creat, path, mode);
}
