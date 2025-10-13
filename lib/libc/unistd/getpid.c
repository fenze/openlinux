#include <unistd.h>
#include <syscall.h>

pid_t getpid(void)
{
	return syscall(getpid);
}
