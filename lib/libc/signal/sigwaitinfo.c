#include <signal.h> // for sigtimedwait, siginfo_t, sigset_t, sigwaitinfo

int sigwaitinfo(const sigset_t *restrict mask, siginfo_t *restrict si)
{
	return sigtimedwait(mask, si, 0);
}
