#include <unistd.h>
#include <syscall.h>
#include <linux/signal.h>

pid_t _Fork(void)
{
	return syscall(clone, SIGCHLD, 0);
}
