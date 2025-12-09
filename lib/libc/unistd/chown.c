


#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for chown, gid_t, uid_t

int chown(const char *path, uid_t owner, gid_t group)
{
	return syscall(chown, path, owner, group);
}
