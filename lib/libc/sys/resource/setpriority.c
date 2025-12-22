#include <sys/resource.h>
#include <syscall.h>

int setpriority(int which, int who, int value)
{
	return syscall(setpriority, which, who, value);
}
