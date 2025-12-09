#include "asm/unistd_64.h" // for __NR_getpid

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for getpid, pid_t

pid_t getpid(void)
{
	return syscall(getpid);
}
