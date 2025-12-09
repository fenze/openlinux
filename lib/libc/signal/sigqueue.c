#include <errno.h>  // for errno
#include <signal.h> // for pthread_sigmask, sigset_t, sigprocmask

int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict old)
{
	int r = pthread_sigmask(how, set, old);

	if (r == 0) {
		return r;
	}

	errno = r;

	return -1;
}
