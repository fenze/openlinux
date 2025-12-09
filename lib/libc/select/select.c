#define __BITS_SELECT_H_
#include "bits/select.h" // for fd_set, timeval (ptr only)


#include <sys/select.h> // for select
#include <syscall.h>	// for __syscall_6, syscall, syscall_arg_t

int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
	   fd_set *restrict errorfds, struct timeval *restrict timeout)
{
	return syscall(pselect6, nfds, readfds, writefds, errorfds, timeout,
		       ((syscall_arg_t[]){ 0, 8 }));
}
