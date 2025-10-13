#include <fcntl.h>
#include <stdarg.h>
#include <syscall.h>

int open(const char *path, int oflag, ...)
{
	long ret;
	mode_t mode = 0;

	if ((oflag & O_CREAT)) {
		va_list ap;
		va_start(ap, oflag);
		mode = va_arg(ap, mode_t);
		va_end(ap);
	}

	ret = syscall(open, path, oflag, mode);

	if (ret >= 0 && (oflag & O_CLOEXEC))
		return syscall(fcntl, ret, F_SETFD, FD_CLOEXEC);

	return ret;
}
