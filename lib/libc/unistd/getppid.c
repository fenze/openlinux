#include "asm/unistd_64.h" // for __NR_getppid

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for getppid, pid_t

pid_t getppid(void)
{
	return syscall(getppid);
}
