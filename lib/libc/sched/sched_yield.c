#include <syscall.h>

int sched_yield(void)
{
	return syscall(sched_yield);
}
