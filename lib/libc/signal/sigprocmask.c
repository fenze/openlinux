

#include <signal.h>  // for sigset_t, sigprocmask
#include <syscall.h> // for __syscall_4, syscall

int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset)
{
	long ret;
	sigset_t oldset = { 0 };

	ret = syscall(rt_sigprocmask, how, set, &oldset, sizeof(sigset_t));

	if (ret < 0)
		return -1;

	if (oset)
		*oset = oldset;
	return 0;
}
