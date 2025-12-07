#include <fcntl.h>
#include <stdarg.h>
#include <syscall.h>

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
