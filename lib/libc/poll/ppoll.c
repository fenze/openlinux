#include "asm/unistd_64.h" // for __NR_ppoll

#include <poll.h>    // for nfds_t, pollfd, ppoll
#include <signal.h>  // for sigset_t
#include <syscall.h> // for __syscall_5, syscall

struct timespec;

int ppoll(struct pollfd fds[], nfds_t nfds,
	  const struct timespec *restrict timeout,
	  const sigset_t *restrict sigmask)
{
	return syscall(ppoll, fds, nfds, timeout, sigmask, 8);
}
