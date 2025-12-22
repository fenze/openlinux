#include <sys/resource.h>
#include <syscall.h>

int getpriority(int which, int who)
{
	int r = syscall(getpriority, which, who);

	if (r < 0)
		return r;

	return 20 - r;
}
