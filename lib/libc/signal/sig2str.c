#include <stdio.h>
#include <string.h>
#include <asm-generic/signal.h>
#include <__signal.h>

int sig2str(int signum, char *str)
{
	if (signum >= SIGHUP && signum <= SIGSYS) {
		strlcpy(str, __sys_signame[signum - SIGHUP],
			sizeof(__sys_signame[signum - SIGHUP]));
		return 0;
	}

	if (signum == SIGRTMIN) {
		strlcpy(str, "SIGRTMIN", sizeof("SIGRTMIN"));
		return 0;
	}

	if (signum == SIGRTMAX) {
		strlcpy(str, "SIGRTMAX", sizeof("SIGRTMAX"));
		return 0;
	}

	if (signum > SIGRTMIN && signum < SIGRTMAX) {
		if (signum - SIGRTMIN <= SIGRTMAX - signum) {
			snprintf(str, sizeof("RTMIN+") + 1, "RTMIN+%d",
				 signum - SIGRTMIN);
		} else {
			snprintf(str, sizeof("RTMAX-") + 1, "RTMAX-%d",
				 SIGRTMAX - signum);
		}
		return 0;
	}

	return -1;
}
