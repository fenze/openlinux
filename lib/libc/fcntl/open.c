#include "asm/unistd_64.h" // for __NR_fcntl, __NR_open

#include <fcntl.h>     // for FD_CLOEXEC, F_SETFD, O_CLOEXEC, O_CREAT
#include <stdarg.h>    // for va_arg, va_end, va_list, va_start
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_3, syscall

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
