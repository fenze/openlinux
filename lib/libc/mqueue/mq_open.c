#include <fcntl.h>
#include <mqueue.h>
#include <stdarg.h>
#include <syscall.h>

mqd_t mq_open(const char *name, int oflag, ...)
{
	mode_t mode;
	struct mq_attr *attr;

	if (*name == '/')
		name++;

	if (oflag & O_CREAT) {
		va_list ap;
		va_start(ap, oflag);
		mode = va_arg(ap, mode_t);
		attr = va_arg(ap, struct mq_attr *);
		va_end(ap);
	} else {
		mode = 0;
		attr = 0;
	}

	return syscall(mq_open, name, oflag, mode, attr);
}
