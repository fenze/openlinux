#include <errno.h>
#include <signal.h>
#include <syscall.h>

int killpg(pid_t pgrp, int sig)
{
	if (pgrp < 0) {
		errno = EINVAL;
		return -1;
	}

	return kill(-pgrp, sig);
}
