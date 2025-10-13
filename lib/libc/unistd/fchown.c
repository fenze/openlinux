#include <unistd.h>
#include <syscall.h>

int fchown(int fildes, uid_t owner, gid_t group)
{
	return syscall(fchown, fildes, owner, group);
}
