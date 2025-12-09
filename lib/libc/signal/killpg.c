#include <errno.h>     // for EINVAL, errno
#include <signal.h>    // for kill, killpg
#include <sys/types.h> // for pid_t

int killpg(pid_t pgrp, int sig)
{
	if (pgrp < 0) {
		errno = EINVAL;
		return -1;
	}

	return kill(-pgrp, sig);
}
