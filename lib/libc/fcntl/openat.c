#include <fcntl.h>
#include <stdarg.h>
#include <syscall.h>

int openat(int fd, const char *path, int oflag, ...)
{
	mode_t mode = 0;

	if (oflag & O_CREAT) {
		va_list ap;
		va_start(ap, oflag);
		mode = va_arg(ap, mode_t);
		va_end(ap);
	}

	return syscall(openat, fd, path, oflag, mode);
}
