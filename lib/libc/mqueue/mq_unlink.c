#include <mqueue.h>
#include <syscall.h>

int mq_unlink(const char *name)
{
	int r;

	if (*name == '/')
		name++;

	r = __syscall(mq_unlink, name);

	if (r < 0) {
		// Correct errno for POSIX compliance
		if (r == -EPERM)
			r = -EACCES;
		errno = -r;
		return -1;
	}

	return r;
}
