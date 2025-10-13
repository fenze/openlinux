#include <unistd.h>
#include <syscall.h>

int lchown(const char *path, uid_t owner, gid_t group)
{
	return syscall(lchown, path, owner, group);
}
