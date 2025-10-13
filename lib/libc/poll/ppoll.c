#include <poll.h>
#include <syscall.h>

int ppoll(struct pollfd fds[], nfds_t nfds,
	  const struct timespec *restrict timeout,
	  const sigset_t *restrict sigmask)
{
	return syscall(ppoll, fds, nfds, timeout, sigmask, 8);
}
