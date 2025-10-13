#include <unistd.h>
#include <syscall.h>

int chown(const char *path, uid_t owner, gid_t group)
{
	return syscall(chown, path, owner, group);
}
