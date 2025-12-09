


#include <syscall.h> // for __syscall_1, syscall
#include <unistd.h>  // for pid_t, getsid

pid_t getsid(pid_t pid)
{
	return syscall(getsid, pid);
}
