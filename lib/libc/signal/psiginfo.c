#include <signal.h> // for psignal, psiginfo, siginfo_t

void psiginfo(const siginfo_t *pinfo, const char *message)
{
	psignal(pinfo->si_signo, message);
}
