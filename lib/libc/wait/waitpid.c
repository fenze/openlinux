#include "asm/unistd_64.h" // for __NR_wait4
#include "sys/types.h"	   // for pid_t

#include <sys/wait.h> // for waitpid
#include <syscall.h>  // for __syscall_4, syscall

pid_t waitpid(pid_t pid, int *stat_loc, int options)
{
	return syscall(wait4, pid, stat_loc, options, 0);
}
