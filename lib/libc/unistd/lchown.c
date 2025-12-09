


#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for gid_t, lchown, uid_t

int lchown(const char *path, uid_t owner, gid_t group)
{
	return syscall(lchown, path, owner, group);
}
