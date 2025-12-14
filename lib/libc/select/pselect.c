

#include <stdint.h>	// for uintptr_t
#include <sys/select.h> // for fd_set, pselect, sigset_t
#include <syscall.h>	// for __syscall_6, syscall, syscall_arg_t
#include <time.h>

struct timespec;

int pselect(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
	    fd_set *restrict errorfds, const struct timespec *restrict timeout,
	    const sigset_t *restrict sigmask)
{
	return syscall(pselect6, nfds, readfds, writefds, errorfds, timeout,
		       ((syscall_arg_t[]){ (uintptr_t)sigmask, 8 }));
}
