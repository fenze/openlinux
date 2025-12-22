#include <sys/resource.h>
#include <syscall.h>

int setrlimit(int resource, const struct rlimit *rlp)
{
	return syscall(setrlimit, resource, rlp);
}
