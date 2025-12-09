#include <signal.h> // for sigaddset, sigset_t

int sigaddset(sigset_t *set, int signo)
{
	if (signo < 1 || signo > 64) {
		return -1;
	}
	*set |= (1ULL << (signo - 1));
	return 0;
}
