#include <unistd.h>
#include <syscall.h>

pid_t getsid(pid_t pid)
{
	return syscall(getsid, pid);
}
