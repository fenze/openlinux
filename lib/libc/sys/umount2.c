

#include <syscall.h> // for __syscall_2, syscall

int umount2(const char *target, int flags)
{
	return syscall(umount2, target, flags);
}
