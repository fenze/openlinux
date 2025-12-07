#include <signal.h>

void psiginfo(const siginfo_t *pinfo, const char *message)
{
	psignal(pinfo->si_signo, message);
}
