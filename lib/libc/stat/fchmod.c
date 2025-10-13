#include <sys/stat.h>
#include <syscall.h>

int fchmod(int fildes, mode_t mode)
{
	return syscall(fchmod, fildes, mode);
}
