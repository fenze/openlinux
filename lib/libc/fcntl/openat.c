


#include <fcntl.h>     // for O_CREAT, openat
#include <stdarg.h>    // for va_arg, va_end, va_list, va_start
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_4, syscall

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
