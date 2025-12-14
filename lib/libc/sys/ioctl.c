

#include <stdarg.h>  // for va_arg, va_end, va_list, va_start
#include <syscall.h> // for __syscall_3, syscall

int ioctl(int fildes, unsigned long request, ...)
{
	void *arg;
	va_list ap;
	va_start(ap, request);
	arg = va_arg(ap, void *);
	va_end(ap);

	return syscall(ioctl, fildes, request, arg);
}
