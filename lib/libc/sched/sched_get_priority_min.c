#include <sched.h>
#include <syscall.h>

int sched_get_priority_min(int policy)
{
	return syscall(sched_get_priority_min, policy);
}
