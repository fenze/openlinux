#include <devctl.h>
#include <sys/cdefs.h>
#include <syscall.h>

int posix_devctl(int fildes, int dcmd, void *restrict dev_data_ptr, size_t __unused nbyte, int *restrict dev_info_ptr)
{
	int r;

	r = syscall(ioctl, fildes, dcmd, dev_data_ptr);
	if (r < 0)
		return errno;

	*dev_info_ptr = r;

	return 0;
}
