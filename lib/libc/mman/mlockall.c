#include "asm/unistd_64.h" // for __NR_mlockall

#include <syscall.h> // for __syscall_1, syscall

int mlockall(int flags)
{
	return syscall(mlockall, flags);
}
