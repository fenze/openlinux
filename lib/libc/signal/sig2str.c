#include <stdio.h>
#include <string.h>
#include <asm-generic/signal.h>
#include <__signal.h>

int sig2str(int signum, char *str)
{
	if (signum >= SIGHUP && signum <= SIGSYS) {
		strcpy(str, __sys_signame[signum - SIGHUP]);
		return 0;
	}

	if (signum == SIGRTMIN) {
		strcpy(str, "SIGRTMIN");
		return 0;
	}

	if (signum == SIGRTMAX) {
		strcpy(str, "RTMAX");
		return 0;
	}

	if (signum > SIGRTMIN && signum < SIGRTMAX) {
		if (signum - SIGRTMIN <= SIGRTMAX - signum) {
			sprintf(str, "RTMIN+%d", signum - SIGRTMIN);
		} else {
			sprintf(str, "RTMAX-%d", SIGRTMAX - signum);
		}
		return 0;
	}

	return -1;
}
