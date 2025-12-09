#include "asm/unistd_64.h" // for __NR_clone

#include <signal.h>  // for SIGCHLD
#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for _Fork, pid_t

pid_t _Fork(void)
{
	return syscall(clone, SIGCHLD, 0);
}
