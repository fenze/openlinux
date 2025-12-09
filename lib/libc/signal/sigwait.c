#include <signal.h> // for sigtimedwait, siginfo_t, sigset_t, sigwait

int sigwait(const sigset_t *restrict mask, int *restrict sig)
{
	siginfo_t si;

	if (sigtimedwait(mask, &si, 0) < 0) {
		return -1;
	}

	*sig = si.si_signo;

	return 0;
}
