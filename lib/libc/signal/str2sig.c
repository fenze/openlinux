#include "stddef.h" // for NULL

#include <__signal.h>		// for __sys_signame
#include <asm-generic/signal.h> // for SIGRTMAX, SIGRTMIN, SIGHUP, SIGSYS
#include <errno.h>		// for errno
#include <stdbool.h>		// for bool
#include <stdlib.h>		// for strtol
#include <string.h>		// for strcmp, strncmp, size_t

int str2sig(const char *restrict str, int *restrict pnum)
{
	for (size_t i = SIGHUP; i <= SIGSYS; ++i) {
		if (!strcmp(str, __sys_signame[i])) {
			*pnum = i;
			return 0;
		}
	}

	if (strcmp(str, "RTMIN") == 0) {
		*pnum = SIGRTMIN;
		return 0;
	}

	if (strcmp(str, "RTMAX") == 0) {
		*pnum = SIGRTMAX;
		return 0;
	}

	int base = 0;
	if (strncmp(str, "RTMIN+", 6) == 0) {
		base = SIGRTMIN;
		str += 5;
	} else if (strncmp(str, "RTMAX-", 6) == 0) {
		base = SIGRTMAX;
		str += 5;
	}

	char *end = NULL;
	errno = 0;
	int offset = strtol(str, &end, 10);
	if (errno || *end) {
		return -1;
	}

	int result = base + offset;
	bool regular = (base == 0 && result >= SIGHUP && result <= SIGSYS);
	bool realtime = (result >= SIGRTMIN && result <= SIGRTMAX);
	if (!regular && !realtime) {
		return -1;
	}

	*pnum = result;
	return 0;
}
