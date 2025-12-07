#include <stdarg.h>
#include <syscall.h>

int ioctl(int fildes, unsigned long request, ...)
{
	void *arg;
	va_list ap;
	va_start(ap, request);
	arg = va_arg(ap, void *);
	va_end(ap);

	return syscall(ioctl, fildes, request, arg);
}
