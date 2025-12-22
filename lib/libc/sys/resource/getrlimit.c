#include <sys/resource.h>
#include <syscall.h>

int getrlimit(int resource, struct rlimit *rlp)
{
	return syscall(getrlimit, resource, rlp);
}
