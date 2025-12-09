#include "asm/unistd_64.h" // for __NR_poll

#include <poll.h>    // for nfds_t, poll, pollfd
#include <syscall.h> // for __syscall_3, syscall

int poll(struct pollfd fds[], nfds_t nfds, int timeout)
{
	return syscall(poll, fds, nfds, timeout);
}
