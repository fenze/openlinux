#include <devctl.h>
#include <errno.h>
#include <stddef.h>
#include <sys/cdefs.h>
#include <syscall.h>

int posix_devctl(int fildes, int dcmd, void *restrict dev_data_ptr, size_t __unused nbyte, int *restrict dev_info_ptr)
{
	int r = syscall(ioctl, fildes, dcmd, dev_data_ptr);

	if (__predict_false(r < 0))
		return errno;

	*dev_info_ptr = r;

	return 0;
}
