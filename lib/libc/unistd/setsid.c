

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for pid_t, setsid

pid_t setsid(void)
{
	return syscall(setsid);
}
