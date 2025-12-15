#include <signal.h>
#include <syscall.h>

int io_uring_enter(unsigned int fd, unsigned int to_submit,
		   unsigned int min_complete, unsigned int flags, sigset_t *sig,
		   size_t sz)
{
	return syscall(io_uring_enter, fd, to_submit, min_complete, flags, sig,
		       sz);
}
