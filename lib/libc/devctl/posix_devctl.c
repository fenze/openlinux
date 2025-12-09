#include "asm/unistd_64.h" // for __NR_ioctl

#include <devctl.h>  // for posix_devctl, size_t
#include <errno.h>   // for errno
#include <libc.h>    // for __unused
#include <syscall.h> // for __syscall_3, syscall

int posix_devctl(int fildes, int dcmd, void *restrict dev_data_ptr,
		 size_t __unused nbyte, int *restrict dev_info_ptr)
{
	long r;

	if ((r = syscall(ioctl, fildes, dcmd, dev_data_ptr)) < 0)
		return errno;

	*dev_info_ptr = r;

	return 0;
}
