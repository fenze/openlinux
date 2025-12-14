

#include <syscall.h> // for __syscall_1, syscall
#include <unistd.h>  // for pid_t, getpgid

pid_t getpgid(pid_t pid)
{
	return syscall(getpgid, pid);
}
