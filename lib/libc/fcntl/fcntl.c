#include "errno.h" // for EINVAL

#include <fcntl.h>   // for F_DUPFD_CLOEXEC, FD_CLOEXEC, F_SETFD, F_D...
#include <stdarg.h>  // for va_arg, va_end, va_list, va_start
#include <syscall.h> // for __syscall_ret, syscall, __syscall_3, __sy...

int fcntl(int fildes, int cmd, ...)
{
	unsigned long arg;
	va_list ap;
	va_start(ap, cmd);
	arg = va_arg(ap, unsigned long);
	va_end(ap);

	if (cmd == F_DUPFD_CLOEXEC) {
		int ret = syscall(fcntl, fildes, F_DUPFD_CLOEXEC, arg);
		if (ret != -EINVAL) {
			if (ret >= 0)
				syscall(fcntl, ret, F_SETFD, FD_CLOEXEC);
			return __syscall_ret(ret);
		}

		ret = syscall(fcntl, fildes, F_DUPFD_CLOEXEC, 0);
		if (ret != -EINVAL) {
			if (ret >= 0)
				__syscall(close, ret);

			return __syscall_ret(-EINVAL);
		}

		ret = syscall(fcntl, fildes, F_DUPFD, arg);
		if (ret >= 0)
			syscall(fcntl, ret, F_SETFD, FD_CLOEXEC);

		return __syscall_ret(ret);
	}

	return syscall(fcntl, fildes, cmd);
}
