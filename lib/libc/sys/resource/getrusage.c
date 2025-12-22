#include <sys/resource.h>
#include <syscall.h>

int getrusage(int who, struct rusage *r_usage)
{
	return syscall(getrusage, who, r_usage);
}
