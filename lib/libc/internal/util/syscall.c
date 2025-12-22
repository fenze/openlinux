#include <errno.h>
#include <sys/cdefs.h>

long __syscall_ret(long ret)
{
	if (__predict_false(ret > -4096 && ret < 0)) {
		errno = (int)-ret;
		ret = -1;
	}

	return ret;
}
