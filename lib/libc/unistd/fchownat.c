#include <unistd.h>
#include <syscall.h>

int fchownat(int fd, const char *path, uid_t owner, gid_t group, int flag)
{
	return syscall(fchownat, fd, path, owner, group, flag);
}
