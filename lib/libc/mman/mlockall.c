#include <syscall.h>
#include <sys/mman.h>

int mlockall(int flags)
{
	return syscall(mlockall, flags);
}
