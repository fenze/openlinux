#include <sched.h>
#include <syscall.h>

int sched_get_priority_max(int policy)
{
	return syscall(sched_get_priority_max, policy);
}
