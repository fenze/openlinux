#include "sys/types.h"	   // for pid_t

#include <sys/wait.h> // for wait
#include <syscall.h>  // for __syscall_4, syscall

pid_t wait(int *stat_loc)
{
	return syscall(wait4, -1, stat_loc, 0, 0);
}
