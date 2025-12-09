


#include <syscall.h> // for __syscall_1, syscall

int mlockall(int flags)
{
	return syscall(mlockall, flags);
}
